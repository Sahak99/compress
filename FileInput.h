#include <string>
#include <fstream>

class FileInput
{
public:
    static bool handleInputFile(const std::string &filename, std::ifstream &ifs);
};