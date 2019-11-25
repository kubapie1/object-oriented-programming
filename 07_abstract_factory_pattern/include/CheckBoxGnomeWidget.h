#pragma once


#include "Widget.h"

class CheckBoxGnomeWidget : public Widget
{
private:
    int gnomeVersion;
public:
    CheckBoxGnomeWidget(int gnomeVersion);
    void draw();
};