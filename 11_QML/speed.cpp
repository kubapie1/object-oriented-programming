#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

double Speed::getCurrentSpeed() const
{
    return speed;
}

void Speed::onDisplacementChanged(double v)
{
    double lastDispalcement = currentDisplacement;
    currentDisplacement = v;
    qDebug() << "[Speed]Displacement changed to: " << v ;
    speed = currentDisplacement - lastDispalcement;
    emit changed(speed);
}
