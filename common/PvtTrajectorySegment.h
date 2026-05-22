#ifndef PVTTRAJECTORYSEGMENT_H
#define PVTTRAJECTORYSEGMENT_H

#include <QVector>

#include "common/TrajectoryPoint.h"

struct PvtTrajectorySegment
{
    QVector<TrajectoryPoint> points;
    qsizetype firstPointIndex = 0;
};

#endif // PVTTRAJECTORYSEGMENT_H
