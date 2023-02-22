#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include "Files.hpp"

class SpecGrep
{
public:
    void searchFor(std::string pattern, std::filesystem::path dir, std::string log, std::string result, int threads);
private:
    void SetPath(std::filesystem::path path);
    void outputResultOnConsole();
    void outputResultInFiles();
    std::vector<Files> filesWithPattern;
    // ConsoleOutput co;
    // FileOutput fo;
};