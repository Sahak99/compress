#include <string>

class Program
{
public:
    void run(int argc, char **argv);

private:
    void handleInputArgs(int argc, char **argv);

private:
    const std::string &m_inputFile;
    const std::string &m_outputFile;
    const std::string &m_algorithm;
};