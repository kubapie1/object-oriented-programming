#pragma once

#include "Widget.h"

class ButtonKdeWidget : public Widget
{
private:
    int kdeVersion;
public:
    ButtonKdeWidget(int kdeVersion);
    void draw();

};