//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_OBSERVER_H
#define INC_06_OBSERVER_PATTERN_OBSERVER_H

#include "Observable.h"

class Observer : public Observable  {
public:
    virtual void notify(float);
};


#endif //INC_06_OBSERVER_PATTERN_OBSERVER_H
