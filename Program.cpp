#include "Program.h"
#include "FileManager.h"
#include <iostream>
#include <string>

void Program::run(int argc, char **argv)
{
    handleInputArgs(argc, argv);
    FileManager<std::ifstream>::handleFileOpen(m_inputFile, m_ifs);
    FileManager<std::ofstream>::handleFileOpen(m_outputFile, m_ofs);
    handleAlgExecution();
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

void Program::handleAlgExecution()
{
    if (m_algorithm == "-rle" || m_algorithm == "-RLE")
    {
        for (std::string inputLine; std::getline(m_ifs, inputLine);)
        {
            std::string outputLine = executeAlg(&Compress::rle, inputLine);
            m_ofs << outputLine << std::endl;
        }
        return;
    }
}

std::string Program::executeAlg(std::function<const std::string(const std::string &)> func, const std::string &str)
{
    return func(str);
}
