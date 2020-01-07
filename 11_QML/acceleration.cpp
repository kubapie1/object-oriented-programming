#include "acceleration.h"
#include <QDebug>
Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onSpeedChanged(double v)
{
    double lastSpeed = currentSpeed;
    currentSpeed = v;
    qDebug() << "[Acceleration]Speed changed to: " << v;
    emit changed((currentSpeed-lastSpeed));
}
