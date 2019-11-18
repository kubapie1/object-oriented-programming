#include "Observable.h"

void Observable::registerObserver(Observer *)
{

}

void Observable::unregisterObserver(Observer *)
{

}

void Observable::notifyObservers(float value)
{
    for( Observer* observer : observers)
        observer->notify(value);
}
