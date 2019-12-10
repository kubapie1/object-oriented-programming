#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    double lastDispalcement = currentDisplacement;
    currentDisplacement = v;
    qDebug() << "[Speed]Displacement changed to: " << v ;
    emit changed(currentDisplacement - lastDispalcement);
}
