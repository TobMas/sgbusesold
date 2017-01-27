#ifndef BUSSERVICE_H
#define BUSSERVICE_H

#include <QObject>

class BusService : public QObject
{
    Q_OBJECT
public:
    explicit BusService(QObject *parent = 0);

signals:

public slots:

private:
    quint16 serviceID;
    quint8 operatorID;          // might be obsolete => replace with QString operatorName
    QString operatorName;
    bool isLoop;                // true for loop services (i.e. direction 1 does not exist)
    float totalDistance;        // in km
    quint16 totalTravelTime;    // in minutes
    QList<QString> busStopIDs;  // sorted list of all bus stops
};

#endif // BUSSERVICE_H
