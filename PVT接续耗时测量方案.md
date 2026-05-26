# PVT接续耗时测量方案

## 目标

在当前 `PVT(PVTS)` 多段接续实现中，测量相邻两段之间的接续耗时，区分：

- 软件侧从检测到前段完成，到启动后段所花的时间
- 电机侧从前段完成，到实际位置重新开始稳定变化所花的时间

本次只做**测量埋点**，不改变当前 `PVT` 接续机制。

## 背景结论

- 当前程序中，后一段 `PVT` 表不是提前预装，而是：
  - 硬件线程周期运行
  - 检测到当前段 `done == true`
  - 若后面还有下一段，则立即调用 `startPvtSegment(next)`
- 因此两段之间出现短暂断续是符合当前实现逻辑的。

## 测量原则

- 所有时间戳均在**硬件线程**中获取
- 使用 `std::chrono::steady_clock`
- 不使用 UI 日志时间做测量
- 只在 `PVT` 多段接续场景启用
- 只测“段间切换”，不测首段启动

## 测量点定义

### 1. T_done

- 含义：
  - 硬件线程确认“当前段已完成”的时刻
- 触发条件：
  - `done == true`
  - 且后面仍有下一段

### 2. T_launch_begin

- 含义：
  - 软件开始执行下一段装表/启动调用的时刻
- 位置：
  - 调用 `startPvtSegment(nextSegmentIndex, ...)` 之前

### 3. T_launch_end

- 含义：
  - 下一段装表/启动调用成功返回的时刻
- 位置：
  - `startPvtSegment(...)` 成功返回之后

### 4. T_motion_resume

- 含义：
  - 从反馈角度观察到电机重新进入稳定运动的时刻
- 位置：
  - 下一段成功启动后，在后续硬件线程周期中检测得到

## 最终要得到的时间量

### 软件接续耗时

- `T_launch_end - T_done`

表示：
- 从前段完成被检测到
- 到下一段装表并再次启动完成

### 实际恢复耗时

- `T_motion_resume - T_done`

表示：
- 从前段完成被检测到
- 到电机重新被观测到稳定运动

### 可选拆分量

也可以同时输出：

- `T_launch_begin - T_done`
- `T_launch_end - T_launch_begin`
- `T_motion_resume - T_launch_end`

便于区分：

- 软件检测与调度耗时
- 装表/启动调用本身耗时
- 启动完成后到反馈重新变化的耗时

## 运动恢复判据

不能使用“位置第一次变化”直接判定恢复，否则容易被量化跳变或抖动误判。

建议判据如下：

### 基准位置

- 在下一段成功启动后，记录：
  - `resumeDetectBasePos = 当前 actualPosRaw`

### 最小变化阈值

- 设定：
  - `resumeThresholdRaw = max(1, round(rawPerDeg * 0.001))`

即最少达到约 `0.001 deg` 对应的原始脉冲变化量。

### 连续确认

- 当 `abs(actualPosRaw - resumeDetectBasePos) >= resumeThresholdRaw` 时，记为候选变化
- 要求连续 `2~3` 个硬件周期仍保持变化，才确认：
  - `T_motion_resume`

这样可以降低以下误判风险：

- 编码器抖动
- 停机边界残余跳变
- 单次量化变化

## 建议的数据结构

本次测量只服务于调试，建议状态仅保存在 `HardwareThread` 内部，不放入共享上下文。

建议增加一组测量状态：

- `bool waitingPvtResumeMeasure`
- `qsizetype measureFromSegmentIndex`
- `qsizetype measureToSegmentIndex`
- `steady_clock::time_point tDone`
- `steady_clock::time_point tLaunchBegin`
- `steady_clock::time_point tLaunchEnd`
- `qint32 resumeDetectBasePos`
- `int resumeConfirmCount`

## 触发流程

### 1. 当前段完成

当硬件线程检测到：

- `done == true`
- 且后面仍有下一段

则：

- 记录 `T_done`
- 记录 `T_launch_begin`
- 调用 `startPvtSegment(next)`

### 2. 下一段启动成功

若 `startPvtSegment(next)` 成功：

- 记录 `T_launch_end`
- 设置“等待恢复检测”状态
- 保存当前实际位置为 `resumeDetectBasePos`

### 3. 后续周期中检测恢复

在后续硬件线程周期中：

- 读取 `actualPosRaw`
- 检查是否超过 `resumeThresholdRaw`
- 连续确认达到阈值后：
  - 记录 `T_motion_resume`
  - 输出日志
  - 清除等待状态

### 4. 异常退出

如果发生：

- 下一段装表失败
- 当前运动被中止
- 最后一段结束

则不进入恢复检测，或中途清空测量状态。

## 日志输出建议

每次成功完成一次段间接续测量后，输出一条总结日志，建议包含：

- 前一段编号
- 后一段编号
- `done -> launch_begin`
- `launch_begin -> launch_end`
- `done -> launch_end`
- `done -> motion_resume`
- `launch_end -> motion_resume`

建议日志格式示例：

```text
PVT 接续耗时：第 1 段 -> 第 2 段，done->launchBegin=0.1ms，launchBegin->launchEnd=1.4ms，done->launchEnd=1.5ms，done->motionResume=4.2ms，launchEnd->motionResume=2.7ms。
```

## 结果解释

### 情况 1

- `done -> launchEnd` 很小
- `done -> motionResume` 明显更大

说明：
- 软件切段动作很快
- 主要延迟来自控制卡/驱动重新开始执行和反馈体现

### 情况 2

- `done -> launchEnd` 已经明显偏大

说明：
- 主要延迟在软件侧装表/启动链路

### 情况 3

- 两者都不大
- 但听感仍有不连续

说明：
- 不连续可能更多体现在速度/力矩连续性
- 不只是单纯的时间空窗

## 本次方案边界

本次先不做以下内容：

- UI 界面展示测量结果
- CSV 导出
- 多次切换统计平均值/最大值
- 自动优化接续策略
- 改变当前 `done` 后再装下一段的接续机制

## 后续实施顺序

1. 在 `HardwareThread` 内部增加测量状态
2. 在 `done -> nextSegment` 切换点埋入 `T_done / T_launch_begin / T_launch_end`
3. 在后续硬件周期加入“恢复运动检测”
4. 输出单条汇总日志
5. 先做联调，再决定是否加统计功能
