#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#include <set>
#include "Observer.h"


//jest to "AGREGACJA" Z OBSERVER

class Observable {
private:
    std::set<Observer*> observers;
public:
    void registerObserver(Observer* observer);
    void unregisterObserver(Observer* observer);
protected:
    void notifyObservers(float value);    //ta pętla
};

#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H