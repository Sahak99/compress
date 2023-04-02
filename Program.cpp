#include "Program.h"
#include <iostream>
#include <string>
void Program::run(int argc, char **argv)
{
    handleInputArgs(argc, argv);
}

void Program::handleInputArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (i == 1 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
        }
        if (i == 2 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
        }
        if (std::to_string(argv[i][0]) == std::to_string('-'))
        {
        }
    }
}
