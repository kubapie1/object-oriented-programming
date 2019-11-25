#pragma once

#include "Widget.h"

class CheckBoxKdeWidget : public Widget
{
private:
    int kdeVersion;
public:
    CheckBoxKdeWidget(int kdeVersion);
    void draw();

};