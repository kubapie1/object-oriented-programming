#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#include <set>
#include "Observer.h"
#include "Displacement.h"


//jest to "AGREGACJA" Z OBSERVER

class Observable : public Observer, public Displacement{

private:
    std::set<Observer*> observers;
public:
    void registerObserver(Observer*);
    void unregisterObserver(Observer*);
protected:
    void notifyObservers(float);    //ta pętla
};

#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H