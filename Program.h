#include <string>
#include <fstream>
#include <functional>
#include <map>

#include "Compress.h"

class Program
{
public:
    void run(int argc, char **argv);

public:
    Program();
    ~Program();

private:
    void handleInputArgs(int argc, char **argv);
    void handleAlgExecution();
    void executeAlg(std::function<const std::string(const std::string &)>,
                    std::ifstream &ifs,
                    std::ofstream &ofs);

private:
    std::string m_inputFile;
    std::string m_outputFile;
    std::string m_algorithm;
    std::ifstream m_ifs;
    std::ofstream m_ofs;
    std::map<std::string, std::function<const std::string(const std::string &)>> m_algMap;
};