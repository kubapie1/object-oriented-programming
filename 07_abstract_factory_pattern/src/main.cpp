#include <iostream>
#include <GnomeWidgetFactory.h>
#include <KdeWidgetFactory.h>
#include "Dummy.h"
#include "Demo.h"
int main() {

    auto dummy = Dummy{};

    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;
    //stworzyc dwa obiekty Demo, z roznymi fabrykami.

    std::shared_ptr<WidgetFactory> factory = std::make_shared<GnomeWidgetFactory>(1);
    std::shared_ptr<WidgetFactory> factory2 = std::make_shared<KdeWidgetFactory>(1234);


    Demo demo(factory);
    demo.run("ListGnomeWidget");

    Demo demo1(factory2);
    demo1.run("ButtonKdeWidget");
    return 0;
}