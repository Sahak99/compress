#include "Program.h"
#include "FileInput.h"
#include <iostream>
#include <string>
#include <fstream>

void Program::run(int argc, char **argv)
{
    std::ifstream ifs;
    handleInputArgs(argc, argv);
    FileInput::handleInputFile(m_inputFile, ifs);
}

void Program::handleInputArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (i == 1 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
            m_inputFile = std::string(argv[i]);
            continue;
        }
        if (i == 2 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
            m_outputFile = std::string(argv[i]);
            continue;
        }
        if (std::to_string(argv[i][0]) == std::to_string('-'))
        {
            m_algorithm = std::string(argv[i]);
        }
    }
}
