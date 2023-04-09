#include <iostream>
#include <string>

#include "Program.h"
#include "../utils/FileManager.h"

void Program::run(int argc, char **argv)
{
    handleInputArgs(argc, argv);
    FileManager<std::ifstream>::handleFileOpen(m_inputFile, m_ifs);
    FileManager<std::ofstream>::handleFileOpen(m_outputFile, m_ofs);
    handleAlgExecution();
}

Program::Program()
{
    m_algMap.insert(std::make_pair("-rle", &Compress::rle));
    m_algMap.insert(std::make_pair("-RLE", &Compress::rle));
    m_algMap.insert(std::make_pair("-drle", &Compress::drle));
    m_algMap.insert(std::make_pair("-dRLE", &Compress::drle));
}

Program::~Program()
{
    if (m_ifs.is_open())
    {
        m_ifs.close();
    }
    if (m_ofs.is_open())
    {
        m_ofs.close();
    }
}

void Program::handleInputArgs(int argc, char **argv)
{

    if (argc == 2)
    {
        if (std::string(argv[1]) == "-help")
        {
            std::cout << "Use this argument format:" << std::endl;
            std::cout << "[input_file_name] [output_file_name] -[algorithm_name]" << std::endl;
            std::cout << "\t---------------------------------------" << std::endl;
            std::cout << "Available algorithm list:" << std::endl;
            std::cout << "'-rle' or '-RLE' : run-length encoding" << std::endl;
            std::cout << "'-drle' or '-dRLE' : run-length encoding (decompress)" << std::endl;
        }
        else
        {
            std::cout << "Please use '-help' for info" << std::endl;
        }
        return;
    }
    if (argc == 3)
    {
        m_inputFile = argv[1];
        m_outputFile = argv[2];
        m_algorithm = "-rle";
        return;
    }

    if (argc == 4)
    {
        m_inputFile = argv[1];
        m_outputFile = argv[2];
        m_algorithm = argv[3];
        return;
    }

    std::cout << "Incorrect argument format, please use '-help' for info" << std::endl;
}

void Program::handleAlgExecution()
{
    executeAlg(m_algMap[m_algorithm], m_ifs, m_ofs);
}

void Program::executeAlg(std::function<const std::string(const std::string &)> func,
                         std::ifstream &ifs,
                         std::ofstream &ofs)
{
    for (std::string inputLine; std::getline(ifs, inputLine);)
    {
        std::string outputLine = func(inputLine);
        ofs << outputLine << std::endl;
    }
}
