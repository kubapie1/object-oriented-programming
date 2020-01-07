#include "acceleration.h"
#include <QDebug>
Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

double Acceleration::getAcceleration() const
{
    return acceleration;
}

void Acceleration::onSpeedChanged(double v)
{
    double lastSpeed = currentSpeed;
    currentSpeed = v;
    qDebug() << "[Acceleration]Speed changed to: " << v;
    acceleration = currentSpeed - lastSpeed;
    emit changed(acceleration);
}
