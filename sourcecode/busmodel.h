#ifndef BUSMODEL_H
#define BUSMODEL_H

#include <QObject>

class BusModel : public QObject
{
    Q_OBJECT
public:
    explicit BusModel(QObject *parent = 0);

    enum driveTrainClass { diesel, gasoline, gas, dieselHybrid, gasolineHybrid, dieselPluginHybrid, gasolinePluginHybrid, fcev, bev };
    enum capacityClass { singledecker, doubledecker, articulated };
    enum emissionClass { none, euro0, euro1, euro2, euro3, euro4, euro5, euro6, euro7, emissionFree };


signals:

public slots:

private:
    driveTrainClass driveTrain;
    capacityClass capacityType;
    quint8 weight;
    quint8 seatingCapacity;
    quint8 standingCapacity;
    QString manufacturer;
    emissionClass emissionStandard;
    float energyDemandDriveTrainKM;
    float energyDemandAirConKM;
};

#endif // BUSMODEL_H
