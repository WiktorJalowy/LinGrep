#pragma once

#include <string>
#include <filesystem>

class SpecGrep
{
public:
    void searchFor(std::string pattern, std::filesystem::path dir, std::string log, std::string result, int threads);
private:
    void SetPath(std::filesystem::path path);
    void outputResultOnConsole();
    void outputResultInFiles();
    // ConsoleOutput co;
    // FileOutput fo;
};