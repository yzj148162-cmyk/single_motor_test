#ifndef FEEDBACKDATA_H
#define FEEDBACKDATA_H

#include <QtGlobal>

enum class TraceStatus : qint8 {
    Inactive = 0,
    Waiting,
    Active,
    Failed
};

// Hardware thread publishes one feedback snapshot per cycle.
struct FeedbackData
{
    qint32 actualPosRaw = 0;
    qint32 targetPosRaw = 0;
    quint16 statusWord = 0;
    qint8 modeDisplay = 0;
    qint32 errorRaw = 0;
    qint32 traceActualPosRaw = 0;
    qint32 traceTargetPosRaw = 0;
    qint32 traceErrorRaw = 0;
    bool traceErrorValid = false;
    TraceStatus traceStatus = TraceStatus::Inactive;
    qint16 traceLastApiResult = 0;
    // Unified motion timeline for the UI.
    double motionTimeS = 0.0;
    bool motionRunning = false;
    bool fault = false;
    bool boardInitialized = false;
};

#endif // FEEDBACKDATA_H
