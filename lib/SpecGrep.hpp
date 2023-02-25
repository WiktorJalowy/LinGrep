#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <chrono>
#include "Files.hpp"
#include "ConsoleOutput.hpp"
#include "FileOutput.hpp"

class SpecGrep
{
public:
    void searchFor(std::string pattern, std::string path, std::string log, std::string result, int threads);
    std::vector<Files> getFiles();
private:
    void SetPath(std::filesystem::path path);
    std::vector<Files> filesWithPattern;
    ConsoleOutput co;
    FileOutput fo;
};