#include "displacement.h"

#include <QDebug>
Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    //if(value == v)return;

    value = v;
    qDebug() << "setDisplacement " << value;
    emit changed(value);
}

double Displacement::getValue() const
{
    return value;
}
