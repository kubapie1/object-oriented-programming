#pragma once


#include "WidgetFactory.h"

class KdeWidgetFactory : public WidgetFactory
{
private:
    int kdeVersion;
public:
    KdeWidgetFactory(int kdeVersion);
    std::shared_ptr<Widget> create(std::string type);
};