#include <iostream>
#include "Dummy.h"

int main() {

    auto dummy = Dummy{};
    //stworzyc dwa obiekty Demo, z roznymi fabrykami.
    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;

    return 0;
}