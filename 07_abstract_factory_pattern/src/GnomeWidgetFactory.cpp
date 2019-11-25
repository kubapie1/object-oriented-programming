//
// Created by student on 25.11.2019.
//

#include <GnomeWidgetFactory.h>
#include <CheckBoxGnomeWidget.h>
#include <ListGnomeWidget.h>
#include <ButtonKdeWidget.h>

GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

std::shared_ptr<Widget> GnomeWidgetFactory::create(std::string type) {
    //std::shared_ptr<Widget>
    if(!type.compare("CheckBoxGnomeWidget"))
        return std::make_shared<CheckBoxGnomeWidget>(gnomeVersion);
    else if(!type.compare("ListGnomeWidget"))
        return std::make_shared<ListGnomeWidget>(gnomeVersion);
    else if(!type.compare("ButtonGnomeWidget"))
        return std::make_shared<ButtonKdeWidget>(gnomeVersion);

    throw std::runtime_error("not that type!");
}

