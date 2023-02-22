#include "ConsoleOutput.hpp"

void ConsoleOutput::outputResults(int filesSearched, int filesWithPattern, int numOfPatterns, std::string resultFile, std::string logFile)
{
    std::cout << "Searched files: " << filesSearched << std::endl
    << "Files with pattern: " << filesWithPattern << std::endl
    << "Patterns number: " << numOfPatterns << std::endl
    << "Result file: " << resultFile << std::endl
    << "Log file: " << logFile << std::endl
    << "Used threads: " << "THREADS" << std::endl
    << "Elapsed time: " << "TIME" << std::endl;
}