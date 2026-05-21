# PVT 模式改造方案

## 1. 目标

在现有单轴 `PVT` 模式下，取消“总轨迹点数必须 `<= 5000`”的限制。

实现方式不是控制卡内部流式续装，而是：

- 软件先生成整条大轨迹
- 按段切分为多个 `PVTS` 子轨迹
- 每段最多 `5000` 点
- 当前段执行完成后，硬件线程立即装载并启动下一段

## 2. 边界约束

- 当前程序里名为 `PVT` 的模式，实际走的是 `PVTS`
- 仍使用公开接口：
  - `dmc_pvts_table_unit`
  - `dmc_pvt_move`
- 不依赖未文档化的 `pvt_continuous` 接口
- 不在“当前段仍在运行时”更新表
- 下一段装载的正式触发条件使用“当前段已结束”

## 3. 核心原则

### 3.1 分段执行

- 整条轨迹先按全局时间轴生成
- 再切成多个 segment
- 每个 segment 独立作为一段 `PVTS` 运动下发

### 3.2 段间边界重叠

相邻 segment 共享 1 个边界点：

- `segment[0]`: 点 `0..4999`
- `segment[1]`: 点 `4999..9998`
- `segment[2]`: 点 `9998..14997`

作用：

- 下一段首点就是上一段末点
- 可保证下一段首点局部位置为 `0`
- 可直接继承上一段末速度作为下一段首速度

### 3.3 局部时间从 0 开始

控制卡看到的每一段 `PVTS` 时间轴都必须是局部时间轴。

处理方式：

- 规划器保留整条轨迹的全局 `timeS`
- 下发某个 segment 时，执行层将该段重基准化：
  - `localTime = point.timeS - segmentFirst.timeS`
  - `localPos = point.pos - segmentFirst.pos`
- 首点强制写为 `0`

这与当前 `startPvtsMotion()` 的实现思路一致。

### 3.4 全局显示时间连续

虽然每段下发给控制卡的时间从 `0` 开始，但 UI 显示的运动时间必须连续。

处理方式：

- 为每个 segment 记录一个 `globalTimeOffset`
- 当前显示时间 = `globalTimeOffset + currentLocalTime`

## 4. 状态判定策略

### 4.1 正式切段条件

正式装载下一段的硬条件：

- `当前段 done == true`

即使用现有封装：

- `EthercatInterface::isAxisMotionDone()`

### 4.2 运行索引的定位

`dmc_pvt_get_run_index` 是库函数，`readPvtRunIndex()` 是现有薄封装。

本次改造中：

- `runIndex` 只作为辅助观测量
- 可用于更新当前目标点、局部时间、日志
- 不作为“允许装下一段”的硬依赖

避免后续实现过度绑定未在公开手册中说明清楚的行为。

## 5. 线程职责

### 5.1 UI 线程

- 允许输入后生成的总点数大于 `5000`
- 不再直接以 `5000` 为参数非法条件
- 仍负责下发一次完整运动请求

### 5.2 规划线程

- 仍负责生成完整全局轨迹
- 新增“按 segment 切分”的输出能力
- 每个 segment 保留：
  - 该段点集
  - 该段首点全局时间
  - 该段末点全局时间

### 5.3 硬件线程

PVT 分支改为“分段状态机”：

- 启动第 0 段
- 运行中监测当前段状态
- 当前段完成后立即装下一段
- 所有段完成后结束整次运动

## 6. 数据结构建议

建议新增 `PvtSegment` 概念，包含：

- `QVector<TrajectoryPoint> points`
- `double globalStartTimeS`
- `double globalEndTimeS`
- `int segmentIndex`

硬件线程侧建议维护：

- `activePvtSegmentIndex_`
- `activePvtSegmentCount_`
- `activePvtTrajectory_`
- `activePvtGlobalTimeOffsetS_`

## 7. 执行流程

1. UI 收集距离、总时间、步长，创建运动请求
2. 规划线程生成完整全局轨迹
3. 规划线程将全局轨迹切成多个 `PvtSegment`
4. 硬件线程启动第 0 段：
   - 取该段点集
   - 做局部时间/位置重基准
   - 调用 `dmc_pvts_table_unit`
   - 调用 `dmc_pvt_move`
5. 运行期间：
   - 可读取 `runIndex` 做显示
   - 持续轮询 `isAxisMotionDone()`
6. 当当前段 `done == true`：
   - 若还有下一段，则立即装载并启动下一段
   - 若无下一段，则整次运动结束
7. UI 曲线与时间显示按全局时间轴连续更新

## 8. 本次实现不做的事

- 不接入 `pvt_continuous`
- 不在当前段运行中覆盖控制卡表
- 不承诺控制卡内部“绝对无缝不断流”
- 不新增 `dmc_*` / `nmc_*` 风格的自定义函数名
- 只改造PVT模式，尽量不影响CSP模式

## 9. 后续编码时必须遵守

- 业务逻辑只调用项目自己的封装名
- `done` 是切段正式条件
- `runIndex` 只做辅助，不做硬条件
- 每段必须局部时间归零
- UI 显示必须保持全局时间连续
- 相邻 segment 必须共享边界点
