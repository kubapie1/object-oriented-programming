#include "demo.h"


Demo::Demo(QObject* parent) : QObject (nullptr)
{
}

int Demo::add(int x, int y)
{
    emit added();
    return x+y;
}
