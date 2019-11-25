#pragma once

#include "Widget.h"

class ListKdeWidget : public Widget
{
private:
    int kdeVersion;
public:
    ListKdeWidget(int kdeVersion);
    void draw();

};