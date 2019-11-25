#include <KdeWidgetFactory.h>
#include <cstring>
#include <CheckBoxKdeWidget.h>
#include <ListKdeWidget.h>
#include <ButtonKdeWidget.h>

KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}

std::shared_ptr<Widget> KdeWidgetFactory::create(std::string type) {
    std::shared_ptr<Widget> widget;

    if(!type.compare("CheckBoxKdeWidget"))
        return std::make_shared<CheckBoxKdeWidget>(kdeVersion);
    else if(!type.compare("ListKdeWidget"))
        return std::make_shared<ListKdeWidget>(kdeVersion);
    else if(!type.compare("ButtonKdeWidget"))
        return std::make_shared<ButtonKdeWidget>(kdeVersion);
    throw std::runtime_error("not that type!");
}


