#pragma once


#include "Widget.h"

class ListGnomeWidget : public Widget
{
private:
    int gnomeVersion;
public:
    ListGnomeWidget(int gnomeVersion);
    void draw();
};