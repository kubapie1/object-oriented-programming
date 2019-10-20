#include <iostream>
#include "Dummy.h"

#include <string>
int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;

    return 0;
}
