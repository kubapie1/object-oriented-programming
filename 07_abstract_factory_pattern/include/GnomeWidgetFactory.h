#pragma once

#include "WidgetFactory.h"

class GnomeWidgetFactory : public WidgetFactory
{
private:
    int gnomeVersion;
public:
    GnomeWidgetFactory(int gnomeVersion);
    std::shared_ptr<Widget> create(std::string type);
};