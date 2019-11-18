//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_ACCELERATION_H
#define INC_06_OBSERVER_PATTERN_ACCELERATION_H


#include "Observer.h"

class Acceleration {
private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
public:
    float get();
};
#endif //INC_06_OBSERVER_PATTERN_ACCELERATION_H
