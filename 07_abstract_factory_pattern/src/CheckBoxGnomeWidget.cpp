//
// Created by student on 25.11.2019.
//

#include <iostream>
#include "CheckBoxGnomeWidget.h"

CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

void CheckBoxGnomeWidget::draw() {
    std::cout<<"CheckBoxGnomeWidget"<< gnomeVersion <<std::endl;
}
