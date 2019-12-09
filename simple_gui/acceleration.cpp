#include "acceleration.h"
#include <QDebug>
Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onSpeedChanged(double v)
{
    qDebug() << "[Acceleration]Speed changed to: " << v;
}
