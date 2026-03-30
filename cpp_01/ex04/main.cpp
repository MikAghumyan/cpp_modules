#include <iostream>
#include <fstream>
#include <string>

void replaceLoop(std::ifstream &inFile, std::ofstream &outFile, char **argv)
{
    std::string findStr(argv[2]);
    std::string replaceStr(argv[3]);
    std::string line;
    while (std::getline(inFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(findStr, pos)) != std::string::npos)
        {
            line.erase(pos, findStr.size());
            line.insert(pos, replaceStr);
            pos += replaceStr.size();
        }
        outFile << line << "\n";
    }
}

bool validateArgs(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "invalid count of arguments" << std::endl;
        return false;
    }
    if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
    {
        std::cerr << "invalid arguments" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (!validateArgs(argc, argv))
        return (1);
    std::string fileName(argv[1]);
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open())
    {
        std::cerr << "Can't open the file" << std::endl;
        return (1);
    }
    std::ofstream outFile((fileName + std::string(".replace")).c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Can't open the file" << std::endl;
        return (1);
    }
    replaceLoop(inFile, outFile, argv);

    return (0);
}
