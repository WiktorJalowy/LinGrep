#pragma once

#include <fstream>
#include <vector>
#include <string>
#include "Files.hpp"

class FileOutput
{
public:
    void outputResult(std::string resultFileName, std::vector<Files> allFiles);
    void outputLog(std::string logFileName, std::vector<Files> allFiles);
private:
};