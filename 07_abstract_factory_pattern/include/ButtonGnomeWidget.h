#pragma once

#include "Widget.h"

class ButtonGnomeWidget : public Widget
{
private:
    int gnomeVersion;
public:
    ButtonGnomeWidget(int gnomeVersion);
    void draw();
};