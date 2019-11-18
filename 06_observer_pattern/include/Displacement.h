//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_DISPLACEMENT_H
#define INC_06_OBSERVER_PATTERN_DISPLACEMENT_H

#include "Observable.h"
#include "Acceleration.h"
#include "Speed.h"

class Displacement : public Observable {
private:
    float value{};
public:
    void set(float);
    Acceleration acceleration;
    Speed speed;
};

#endif //INC_06_OBSERVER_PATTERN_DISPLACEMENT_H
