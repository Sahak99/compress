#include "Program.h"
#include <iostream>

void Program::run(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }
}
