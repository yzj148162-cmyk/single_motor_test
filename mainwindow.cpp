#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QDateTime>
#include <QLabel>
#include <QMutexLocker>
#include <QPainter>
#include <QPainterPath>
#include <QRadioButton>
#include <QThread>
#include <QVBoxLayout>
#include <QVector>
#include <QtMath>
#include <algorithm>
#include <chrono>
#include <limits>

namespace {
constexpr double kEps = 1e-6;
constexpr double kPlotWindowS = 15.0;
constexpr double kPlotKeepHistoryS = 120.0;
constexpr int kMinUiRefreshMs = 10;
constexpr int kMaxUiRefreshMs = 500;
constexpr double kPulseEquivalentPerDegree = 500.622;
constexpr double kPulseEquivalentPerTurn = 180224.0;
constexpr double kErrorPlotMinHalfRangeDeg = 0.001;
constexpr int kErrorPlotDecimals = 3;
constexpr auto kShutdownSafetyTimeout = std::chrono::seconds(2);
const QColor kPrimaryErrorColor(220, 53, 69);
const QColor kTraceErrorColor(13, 110, 253);

double rawToDisplayUnit(qint32 rawValue, double pulsePerUnit)
{
    if (std::fabs(pulsePerUnit) < kEps) {
        return 0.0;
    }
    return static_cast<double>(rawValue) / pulsePerUnit;
}

double rawToDegree(qint32 rawValue)
{
    return rawToDisplayUnit(rawValue, kPulseEquivalentPerDegree);
}

QString traceStatusToText(TraceStatus status, qint16 lastApiResult)
{
    switch (status) {
    case TraceStatus::Inactive:
        return QStringLiteral("未启动");
    case TraceStatus::Waiting:
        return QStringLiteral("等待首帧");
    case TraceStatus::Active:
        return QStringLiteral("采集中");
    case TraceStatus::Failed:
        return QStringLiteral("配置失败/重试中 (rc=%1)").arg(lastApiResult);
    }

    return QStringLiteral("未知");
}

} // namespace

class ErrorPlotWidget : public QWidget
{
public:
    explicit ErrorPlotWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        setMinimumHeight(240);
        setAutoFillBackground(true);
    }

    void setUnitSuffix(const QString &unitSuffix)
    {
        unitSuffix_ = unitSuffix;
        update();
    }

    void clearSamples()
    {
        primarySamples_.clear();
        traceSamples_.clear();
        update();
    }

    void appendPrimarySample(double timeS, double errorValue)
    {
        primarySamples_.push_back(QPointF(timeS, errorValue));
        trimSeries(primarySamples_);
        update();
    }

    void appendTraceSample(double timeS, double errorValue)
    {
        traceSamples_.push_back(QPointF(timeS, errorValue));
        trimSeries(traceSamples_);
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QWidget::paintEvent(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.fillRect(rect(), QColor(248, 249, 250));

        const QRectF plotRect(55, 20, width() - 75, height() - 55);
        painter.setPen(QPen(Qt::black, 1.0));
        painter.drawRect(plotRect);

        if (primarySamples_.isEmpty() && traceSamples_.isEmpty()) {
            painter.drawText(plotRect, Qt::AlignCenter, QStringLiteral("暂无误差数据"));
            return;
        }

        double latestX = 0.0;
        if (!primarySamples_.isEmpty()) {
            latestX = std::max(latestX, primarySamples_.back().x());
        }
        if (!traceSamples_.isEmpty()) {
            latestX = std::max(latestX, traceSamples_.back().x());
        }

        const double xMax = std::max(kPlotWindowS, latestX);
        const double xMin = std::max(0.0, xMax - kPlotWindowS);

        double yMin = std::numeric_limits<double>::max();
        double yMax = std::numeric_limits<double>::lowest();
        bool hasVisible = false;
        updateVisibleRange(primarySamples_, xMin, hasVisible, yMin, yMax);
        updateVisibleRange(traceSamples_, xMin, hasVisible, yMin, yMax);

        if (!hasVisible) {
            painter.drawText(plotRect, Qt::AlignCenter, QStringLiteral("暂无可见误差数据"));
            return;
        }

        if (std::fabs(yMax - yMin) < kEps) {
            yMin -= kErrorPlotMinHalfRangeDeg;
            yMax += kErrorPlotMinHalfRangeDeg;
        } else {
            const double pad = std::max(0.15 * (yMax - yMin), kErrorPlotMinHalfRangeDeg);
            yMin -= pad;
            yMax += pad;
        }

        auto mapPoint = [&](const QPointF &src) {
            const double xRatio = (src.x() - xMin) / std::max(kEps, xMax - xMin);
            const double yRatio = (src.y() - yMin) / std::max(kEps, yMax - yMin);
            return QPointF(plotRect.left() + xRatio * plotRect.width(),
                           plotRect.bottom() - yRatio * plotRect.height());
        };

        painter.setPen(QPen(QColor(34, 139, 34), 1.0, Qt::DashLine));
        painter.drawLine(mapPoint(QPointF(xMin, 0.0)), mapPoint(QPointF(xMax, 0.0)));

        drawSeries(painter, primarySamples_, xMin, mapPoint, kPrimaryErrorColor);
        drawSeries(painter, traceSamples_, xMin, mapPoint, kTraceErrorColor);
        drawLegend(painter, plotRect);

        painter.setPen(Qt::black);
        painter.drawText(QRectF(5, plotRect.top() - 8, 45, 20),
                         Qt::AlignRight | Qt::AlignVCenter,
                         QString::number(yMax, 'f', kErrorPlotDecimals));
        painter.drawText(QRectF(5, plotRect.bottom() - 10, 45, 20),
                         Qt::AlignRight | Qt::AlignVCenter,
                         QString::number(yMin, 'f', kErrorPlotDecimals));
        painter.drawText(QRectF(plotRect.left(), plotRect.bottom() + 5, 80, 20),
                         Qt::AlignLeft | Qt::AlignTop,
                         QString::number(xMin, 'f', 2) + QStringLiteral(" s"));
        painter.drawText(QRectF(plotRect.right() - 80, plotRect.bottom() + 5, 80, 20),
                         Qt::AlignRight | Qt::AlignTop,
                         QString::number(xMax, 'f', 2) + QStringLiteral(" s"));
        painter.drawText(QRectF(plotRect.left(), 0, plotRect.width(), 20),
                         Qt::AlignCenter,
                         QStringLiteral("位置误差对比曲线 (%1)").arg(unitSuffix_.trimmed()));
    }

private:
    template <typename MapFn>
    void drawSeries(QPainter &painter,
                    const QVector<QPointF> &samples,
                    double xMin,
                    const MapFn &mapPoint,
                    const QColor &color) const
    {
        QPainterPath path;
        bool started = false;
        for (const QPointF &pt : samples) {
            if (pt.x() + 1e-9 < xMin) {
                continue;
            }

            const QPointF mapped = mapPoint(pt);
            if (!started) {
                path.moveTo(mapped);
                started = true;
            } else {
                path.lineTo(mapped);
            }
        }

        if (!started) {
            return;
        }

        painter.setPen(QPen(color, 2.0));
        painter.drawPath(path);
    }

    static void updateVisibleRange(const QVector<QPointF> &samples,
                                   double xMin,
                                   bool &hasVisible,
                                   double &yMin,
                                   double &yMax)
    {
        for (const QPointF &pt : samples) {
            if (pt.x() + 1e-9 < xMin) {
                continue;
            }
            hasVisible = true;
            yMin = std::min(yMin, pt.y());
            yMax = std::max(yMax, pt.y());
        }
    }

    static void trimSeries(QVector<QPointF> &samples)
    {
        while (samples.size() > 2 && (samples.back().x() - samples.front().x()) > kPlotKeepHistoryS) {
            samples.removeFirst();
        }
    }

    void drawLegend(QPainter &painter, const QRectF &plotRect) const
    {
        const QRectF legendRect(plotRect.right() - 170, plotRect.top() + 10, 160, 42);
        painter.fillRect(legendRect, QColor(255, 255, 255, 220));
        painter.setPen(QPen(QColor(180, 180, 180), 1.0));
        painter.drawRect(legendRect);

        painter.setPen(QPen(kPrimaryErrorColor, 2.0));
        painter.drawLine(QPointF(legendRect.left() + 8, legendRect.top() + 14),
                         QPointF(legendRect.left() + 28, legendRect.top() + 14));
        painter.setPen(Qt::black);
        painter.drawText(QRectF(legendRect.left() + 34, legendRect.top() + 5, 120, 18),
                         Qt::AlignLeft | Qt::AlignVCenter,
                         QStringLiteral("原误差"));

        painter.setPen(QPen(kTraceErrorColor, 2.0));
        painter.drawLine(QPointF(legendRect.left() + 8, legendRect.top() + 30),
                         QPointF(legendRect.left() + 28, legendRect.top() + 30));
        painter.setPen(Qt::black);
        painter.drawText(QRectF(legendRect.left() + 34, legendRect.top() + 21, 120, 18),
                         Qt::AlignLeft | Qt::AlignVCenter,
                         QStringLiteral("0x60F4 Trace"));
    }

    QVector<QPointF> primarySamples_;
    QVector<QPointF> traceSamples_;
    QString unitSuffix_ = QStringLiteral("deg");
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , hardwareThread_(new HardwareThread(sharedContext_, systemConfig_, this))
    , plannerThread_(new PlannerThread(sharedContext_, systemConfig_, this))
    , uiRefreshController_(new UiRefreshController(sharedContext_, systemConfig_, this))
{
    ui_->setupUi(this);
    setupRuntimeUi();
    connectSignals();
    startThreads();

    appendLog(QStringLiteral("多线程控制框架已启动：系统规划周期用于轨迹采样，UI 刷新周期只负责显示。"));
}

MainWindow::~MainWindow()
{
    stopThreads();
    delete ui_;
}

void MainWindow::setupRuntimeUi()
{
    ui_->modeCombo->clear();
    ui_->modeCombo->addItem(QStringLiteral("PVT"), static_cast<int>(MotionMode::PVT));
    ui_->modeCombo->addItem(QStringLiteral("CSP"), static_cast<int>(MotionMode::CSP));

    ui_->trajectoryShapeCombo->clear();
    ui_->trajectoryShapeCombo->addItem(QStringLiteral("点动轨迹"), static_cast<int>(TrajectoryShape::Jog));
    ui_->trajectoryShapeCombo->addItem(QStringLiteral("正弦轨迹"), static_cast<int>(TrajectoryShape::Sine));

    ui_->systemPlanningPeriodMsSpin->setRange(1, 1000);
    ui_->uiRefreshMsSpin->setRange(kMinUiRefreshMs, kMaxUiRefreshMs);
    ui_->uiRefreshMsSpin->setValue(systemConfig_.uiRefreshMs);

    ui_->positionUnitLabel->setText(QStringLiteral("位置单位"));
    ui_->degreeUnitRadio->setText(QStringLiteral("角度"));
    ui_->turnUnitRadio->setText(QStringLiteral("圈数"));
    ui_->deltaAngleLabel->setText(QStringLiteral("点动位移"));
    ui_->durationLabel->setText(QStringLiteral("轨迹时长"));
    ui_->traceStatusLabel->setText(QStringLiteral("未启动"));

    auto *plotLayout = new QVBoxLayout(ui_->errorPlotHost);
    plotLayout->setContentsMargins(0, 0, 0, 0);

    errorPlot_ = new ErrorPlotWidget(ui_->errorPlotHost);
    plotLayout->addWidget(errorPlot_);

    ui_->tipLabel->setText(
        QStringLiteral("1. 系统规划周期用于上层轨迹采样，PVT 直接下发表点，CSP 会继续细化到 1ms。\n"
                       "2. 正弦轨迹按幅值 A 和角频率 ω 生成位置 A*sin(ωt)。\n"
                       "3. 勾选往复运动后，会先按设定轨迹正向执行，再按同一轨迹反向返回起点。\n"
                       "4. 位置单位可在角度和圈数之间切换，初始化控制卡时会同步下发对应脉冲当量。\n"
                       "5. UI 刷新周期只负责界面显示，不参与实时控制。"));

    applyUiRefreshPeriod();
    applyPositionUnitSelection();
    applyTrajectorySelection();
}

void MainWindow::connectSignals()
{
    connect(ui_->initCardButton, &QPushButton::clicked, this, &MainWindow::onInitCard);
    connect(ui_->closeCardButton, &QPushButton::clicked, this, &MainWindow::onCloseCard);
    connect(ui_->enableAxisButton, &QPushButton::clicked, this, &MainWindow::onEnableAxis);
    connect(ui_->disableAxisButton, &QPushButton::clicked, this, &MainWindow::onDisableAxis);
    connect(ui_->readPosButton, &QPushButton::clicked, this, &MainWindow::onReadPosition);
    connect(ui_->startButton, &QPushButton::clicked, this, &MainWindow::onStartMotion);
    connect(ui_->stopButton, &QPushButton::clicked, this, &MainWindow::onStopMotion);
    connect(ui_->uiRefreshMsSpin, &QSpinBox::valueChanged, this, [this](int) { applyUiRefreshPeriod(); });
    connect(ui_->degreeUnitRadio, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) {
            applyPositionUnitSelection();
        }
    });
    connect(ui_->turnUnitRadio, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) {
            applyPositionUnitSelection();
        }
    });
    connect(ui_->trajectoryShapeCombo,
            &QComboBox::currentIndexChanged,
            this,
            [this](int) { applyTrajectorySelection(); });

    connect(hardwareThread_, &HardwareThread::logMessage, this, &MainWindow::onHardwareLog);
    connect(plannerThread_, &PlannerThread::logMessage, this, &MainWindow::onPlannerLog);
    connect(hardwareThread_, &HardwareThread::boardStateChanged, this, &MainWindow::onBoardStateChanged);
    connect(uiRefreshController_, &UiRefreshController::snapshotReady, this, &MainWindow::updateSnapshot);
}

void MainWindow::startThreads()
{
    sharedContext_.running.storeRelease(1);
    hardwareThread_->start();
    plannerThread_->start();
    uiRefreshController_->start();
}

void MainWindow::stopThreads()
{
    uiRefreshController_->stop();

    requestSafeControllerShutdown();

    sharedContext_.running.storeRelease(0);
    {
        QMutexLocker locker(&sharedContext_.plannerMutex);
        sharedContext_.plannerWakeup = true;
    }
    sharedContext_.plannerWaitCondition.wakeAll();

    if (hardwareThread_->isRunning()) {
        hardwareThread_->wait();
    }
    if (plannerThread_->isRunning()) {
        plannerThread_->wait();
    }
}

void MainWindow::requestSafeControllerShutdown()
{
    if (hardwareThread_ == nullptr || !hardwareThread_->isRunning()) {
        return;
    }

    bool controllerOpen = boardInitialized_;
    {
        QMutexLocker locker(&sharedContext_.feedbackMutex);
        controllerOpen = controllerOpen || sharedContext_.feedback.boardInitialized;
    }
    if (!controllerOpen) {
        return;
    }

    const MotionConfig config = collectMotionConfig();
    hardwareThread_->enqueueCommand({HardwareCommand::Type::StopMotion, config});
    hardwareThread_->enqueueCommand({HardwareCommand::Type::DisableAxis, config});
    hardwareThread_->enqueueCommand({HardwareCommand::Type::CloseBoard, config});

    const auto deadline = std::chrono::steady_clock::now() + kShutdownSafetyTimeout;
    while (std::chrono::steady_clock::now() < deadline) {
        bool boardStillOpen = boardInitialized_;
        {
            QMutexLocker locker(&sharedContext_.feedbackMutex);
            boardStillOpen = boardStillOpen || sharedContext_.feedback.boardInitialized;
        }
        if (!boardStillOpen) {
            break;
        }
        QThread::msleep(10);
    }
}

void MainWindow::appendLog(const QString &text)
{
    const QString stamp = QDateTime::currentDateTime().toString("HH:mm:ss.zzz");
    ui_->logEdit->appendPlainText(QStringLiteral("[%1] %2").arg(stamp, text));
}

void MainWindow::applyUiRefreshPeriod()
{
    const int uiRefreshMs = std::clamp(ui_->uiRefreshMsSpin->value(), kMinUiRefreshMs, kMaxUiRefreshMs);
    systemConfig_.uiRefreshMs = uiRefreshMs;
    uiRefreshController_->setRefreshIntervalMs(uiRefreshMs);
}

void MainWindow::applyPositionUnitSelection()
{
    const QString positionUnitSuffix = currentPositionUnitSuffix();
    const QString velocityUnitSuffix = currentVelocityUnitSuffix();

    ui_->deltaAngleSpin->setSuffix(positionUnitSuffix);
    ui_->minVelSpin->setSuffix(velocityUnitSuffix);
    ui_->maxVelSpin->setSuffix(velocityUnitSuffix);
    ui_->sineAmplitudeSpin->setSuffix(positionUnitSuffix);
    ui_->positionLabel->setText(QStringLiteral("--") + positionUnitSuffix);
    ui_->errorLabel->setText(QStringLiteral("当前位置误差: --%1").arg(positionUnitSuffix));
    if (errorPlot_ != nullptr) {
        errorPlot_->setUnitSuffix(QStringLiteral("deg"));
    }
}

void MainWindow::applyTrajectorySelection()
{
    const TrajectoryShape shape =
        static_cast<TrajectoryShape>(ui_->trajectoryShapeCombo->currentData().toInt());
    const bool sineSelected = (shape == TrajectoryShape::Sine);

    ui_->deltaAngleSpin->setEnabled(!sineSelected);
    ui_->deltaAngleLabel->setEnabled(!sineSelected);
    ui_->sineAmplitudeSpin->setEnabled(sineSelected);
    ui_->sineAmplitudeLabel->setEnabled(sineSelected);
    ui_->sineOmegaSpin->setEnabled(sineSelected);
    ui_->sineOmegaLabel->setEnabled(sineSelected);
}

double MainWindow::currentPulseEquivalent() const
{
    return ui_->turnUnitRadio->isChecked() ? kPulseEquivalentPerTurn : kPulseEquivalentPerDegree;
}

QString MainWindow::currentPositionUnitSuffix() const
{
    return ui_->turnUnitRadio->isChecked() ? QStringLiteral(" 圈") : QStringLiteral(" deg");
}

QString MainWindow::currentVelocityUnitSuffix() const
{
    return ui_->turnUnitRadio->isChecked() ? QStringLiteral(" 圈/s") : QStringLiteral(" deg/s");
}

MotionConfig MainWindow::collectMotionConfig() const
{
    MotionConfig config;
    config.mode = static_cast<MotionMode>(ui_->modeCombo->currentData().toInt());
    config.trajectoryShape =
        static_cast<TrajectoryShape>(ui_->trajectoryShapeCombo->currentData().toInt());
    config.axis = static_cast<quint16>(ui_->axisSpin->value());
    config.deltaDeg = ui_->deltaAngleSpin->value();
    config.durationS = ui_->durationSpin->value();
    config.sineAmplitude = ui_->sineAmplitudeSpin->value();
    config.sineAngularFrequency = ui_->sineOmegaSpin->value();
    config.reciprocating = ui_->reciprocatingCheck->isChecked();
    config.systemPlanningPeriodMs = ui_->systemPlanningPeriodMsSpin->value();
    config.minVelDeg = ui_->minVelSpin->value();
    config.maxVelDeg = ui_->maxVelSpin->value();
    config.rawPerDeg = currentPulseEquivalent();
    config.ecatPort = static_cast<quint16>(ui_->ecatPortSpin->value());
    config.node = static_cast<quint16>(1000 + ui_->nodeSpin->value());
    config.cspInterpPeriodMs = ui_->cspInterpPeriodMsSpin->value();
    config.cspInterpIndex = ui_->cspInterpIndexSpin->value();
    config.cspRxpdoPosAddr = static_cast<quint16>(ui_->cspRxpdoPosAddrSpin->value());
    config.cspTxpdoStatusAddr = static_cast<quint16>(ui_->cspTxpdoStatusAddrSpin->value());
    config.cspTxpdoModeAddr = static_cast<quint16>(ui_->cspTxpdoModeAddrSpin->value());
    config.cspTxpdoPosAddr = static_cast<quint16>(ui_->cspTxpdoPosAddrSpin->value());
    return config;
}

void MainWindow::updateSnapshot(const UiSnapshot &snapshot)
{
    const double pulsePerUnit = currentPulseEquivalent();
    const QString positionUnitSuffix = currentPositionUnitSuffix();
    const double actualPosDisplay = rawToDisplayUnit(snapshot.feedback.actualPosRaw, pulsePerUnit);
    const double errorDisplay = rawToDisplayUnit(snapshot.feedback.errorRaw, pulsePerUnit);
    const double errorDisplayDeg = rawToDegree(snapshot.feedback.errorRaw);
    const double traceErrorDisplay = rawToDisplayUnit(snapshot.feedback.traceErrorRaw, pulsePerUnit);
    const double traceErrorDisplayDeg = rawToDegree(snapshot.feedback.traceErrorRaw);

    ui_->connectionLabel->setText(snapshot.feedback.boardInitialized ? QStringLiteral("已初始化")
                                                                     : QStringLiteral("未初始化"));
    ui_->positionLabel->setText(QString::number(actualPosDisplay, 'f', 4) + positionUnitSuffix);
    ui_->stateLabel->setText(snapshot.feedback.motionRunning ? QStringLiteral("运行中")
                                                             : QStringLiteral("空闲/监测"));
    ui_->queueLabel->setText(QString::number(snapshot.queueDepth));
    ui_->cycleLabel->setText(QStringLiteral("已发送 %1，补队列 %2")
                                 .arg(snapshot.sentPointCount)
                                 .arg(snapshot.queueFillCount));
    ui_->traceStatusLabel->setText(traceStatusToText(snapshot.feedback.traceStatus,
                                                     snapshot.feedback.traceLastApiResult));

    QString errorLabelText = QStringLiteral("当前位置误差: %1%2")
                                 .arg(QString::number(errorDisplay, 'f', 4))
                                 .arg(positionUnitSuffix);
    if (snapshot.feedback.traceErrorValid) {
        errorLabelText += QStringLiteral(" | 0x60F4 Trace误差: %1%2")
                              .arg(QString::number(traceErrorDisplay, 'f', 4))
                              .arg(positionUnitSuffix);
    }
    ui_->errorLabel->setText(errorLabelText);

    if (errorPlot_ != nullptr) {
        const bool appendDuringMotion = curveCaptureActive_ && snapshot.feedback.motionRunning;
        const bool appendTerminalPoint = curveCaptureActive_ && !snapshot.feedback.motionRunning
                                      && lastMotionRunning_ && snapshot.feedback.motionTimeS > 0.0;
        if (appendDuringMotion || appendTerminalPoint) {
            errorPlot_->appendPrimarySample(snapshot.feedback.motionTimeS, errorDisplayDeg);
            if (snapshot.feedback.traceErrorValid) {
                errorPlot_->appendTraceSample(snapshot.feedback.motionTimeS, traceErrorDisplayDeg);
            }
        }
    }

    if (curveCaptureActive_ && !snapshot.feedback.motionRunning && lastMotionRunning_) {
        curveCaptureActive_ = false;
    }
    lastMotionRunning_ = snapshot.feedback.motionRunning;
}

void MainWindow::onInitCard()
{
    hardwareThread_->enqueueCommand({HardwareCommand::Type::InitializeBoard, collectMotionConfig()});
}

void MainWindow::onCloseCard()
{
    hardwareThread_->enqueueCommand({HardwareCommand::Type::CloseBoard, collectMotionConfig()});
}

void MainWindow::onEnableAxis()
{
    if (!boardInitialized_) {
        appendLog(QStringLiteral("控制卡尚未初始化。"));
        return;
    }

    const MotionConfig config = collectMotionConfig();
    hardwareThread_->enqueueCommand({HardwareCommand::Type::EnableAxis, config});
    appendLog(QStringLiteral("UI 已下发轴使能命令，axis=%1。").arg(config.axis));
}

void MainWindow::onDisableAxis()
{
    if (!boardInitialized_) {
        appendLog(QStringLiteral("控制卡尚未初始化。"));
        return;
    }

    const MotionConfig config = collectMotionConfig();
    hardwareThread_->enqueueCommand({HardwareCommand::Type::DisableAxis, config});
    appendLog(QStringLiteral("UI 已下发轴失能命令，axis=%1。").arg(config.axis));
}

void MainWindow::onStartMotion()
{
    if (!boardInitialized_) {
        appendLog(QStringLiteral("控制卡尚未初始化。"));
        return;
    }

    const MotionConfig config = collectMotionConfig();
    if (config.maxVelDeg < config.minVelDeg || config.maxVelDeg <= 0.0) {
        appendLog(QStringLiteral("参数非法：最大速度必须大于等于最小速度，且必须大于 0。"));
        return;
    }
    if (config.systemPlanningPeriodMs <= 0 || config.systemPlanningPeriodMs > qRound(config.durationS * 1000.0)) {
        appendLog(QStringLiteral("参数非法：系统规划周期必须大于 0，且不能超过总时长。"));
        return;
    }
    if (config.trajectoryShape == TrajectoryShape::Sine) {
        if (config.sineAmplitude <= 0.0) {
            appendLog(QStringLiteral("参数非法：正弦轨迹幅值必须大于 0。"));
            return;
        }
        if (config.sineAngularFrequency <= 0.0) {
            appendLog(QStringLiteral("参数非法：正弦轨迹角频率必须大于 0。"));
            return;
        }
    }

    {
        QMutexLocker locker(&sharedContext_.requestMutex);
        sharedContext_.motionRequest.config = config;
        sharedContext_.motionRequest.active = true;
        sharedContext_.motionRequest.restartRequested = true;
        ++sharedContext_.motionRequest.sequenceId;
    }

    if (errorPlot_ != nullptr) {
        errorPlot_->clearSamples();
    }
    curveCaptureActive_ = true;
    lastMotionRunning_ = false;

    hardwareThread_->enqueueCommand({HardwareCommand::Type::StartMotion, config});
    appendLog(QStringLiteral("UI 已下发开始命令，mode=%1，轨迹=%2，系统规划周期=%3ms，UI 显示周期=%4ms，往复=%5。")
                  .arg(motionModeToString(config.mode))
                  .arg(trajectoryShapeToString(config.trajectoryShape))
                  .arg(config.systemPlanningPeriodMs)
                  .arg(systemConfig_.uiRefreshMs)
                  .arg(config.reciprocating ? QStringLiteral("on") : QStringLiteral("off")));
}

void MainWindow::onStopMotion()
{
    {
        QMutexLocker locker(&sharedContext_.requestMutex);
        sharedContext_.motionRequest.active = false;
        sharedContext_.motionRequest.restartRequested = false;
    }

    hardwareThread_->enqueueCommand({HardwareCommand::Type::StopMotion, collectMotionConfig()});
    appendLog(QStringLiteral("UI 已下发停止命令。"));
    curveCaptureActive_ = false;
    lastMotionRunning_ = false;
}

void MainWindow::onReadPosition()
{
    if (!boardInitialized_) {
        appendLog(QStringLiteral("控制卡尚未初始化。"));
        return;
    }

    const MotionConfig config = collectMotionConfig();
    hardwareThread_->enqueueCommand({HardwareCommand::Type::ReadActualPosition, config});
    appendLog(QStringLiteral("UI 已下发读取实际位置命令，axis=%1。").arg(config.axis));
}

void MainWindow::onHardwareLog(const QString &message)
{
    appendLog(QStringLiteral("[硬件线程] %1").arg(message));
}

void MainWindow::onPlannerLog(const QString &message)
{
    appendLog(QStringLiteral("[规划线程] %1").arg(message));
}

void MainWindow::onBoardStateChanged(bool initialized)
{
    boardInitialized_ = initialized;
    ui_->connectionLabel->setText(initialized ? QStringLiteral("已初始化")
                                              : QStringLiteral("未初始化"));
    ui_->degreeUnitRadio->setEnabled(!initialized);
    ui_->turnUnitRadio->setEnabled(!initialized);
}
