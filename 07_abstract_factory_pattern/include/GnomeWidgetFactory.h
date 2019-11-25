#pragma once

class GnomeWidgetFactory
{
private:
    int gnomeVersion;
public:
    GnomeWidgetFactory(int gnomeVersion);
    std::shared_ptr<Widget> create(std::string type);
};