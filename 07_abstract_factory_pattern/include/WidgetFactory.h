#pragma once

#include "Widget.h"
#include <memory>

class WidgetFactory
{
public:
    virtual std::shared_ptr<Widget> create(std::string type) = 0;
};