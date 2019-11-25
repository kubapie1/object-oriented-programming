#pragma once



class KdeWidgetFactory
{
private:
    int kdeVersion;
public:
    KdeWidgetFactory(int kdeVersion);
    std::shared_ptr<Widget> create(std::string type);
};