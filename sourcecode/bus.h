#ifndef BUS_H
#define BUS_H

#include <QObject>
#include "busmodel.h"

class Bus : public QObject
{
    Q_OBJECT
public:
    explicit Bus(QObject *parent = 0);

signals:

public slots:

private:
    BusModel model;
    quint16 registrationNumber, currentServiceID;
    quint8 currentDirection, currentTripID;


};

#endif // BUS_H
