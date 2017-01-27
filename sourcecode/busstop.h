#ifndef BUSSTOP_H
#define BUSSTOP_H

#include <QObject>
#include <QVector>

class BusStop : public QObject
{
    Q_OBJECT
public:
    explicit BusStop(QObject *parent = 0);

signals:

public slots:

private:
    QString id;      // id of the bus stop
    double longitude, latitude;
    QVector<quint16> serviceIDs;        // IDs of services calling at this bus stop (QVector of class BusService is probably not necessary)
    QVector<QString> nextBusStopIDs;    // IDs of next bus stops ('next' depends on routes) (might be better to have bus stop pairs or routes)
    QVector<float> distanceToNextBusStops;  // distances from this bus stop to all next bus stops

};

#endif // BUSSTOP_H
