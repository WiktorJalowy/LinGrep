#include "SpecGrep.hpp"

void SpecGrep::searchFor(std::string pattern, std::filesystem::path dir = ".", std::string log = "SpecGrep.log", std::string result = "SpecGrep.txt", int threads = 4)
{
    SetPath(dir);
    
    //1. searching for pattern in specified or default directory
    //2. remembering every file in which pattern was found, the number of files with pattern, number of patterns in files, number of line
    //3. from every file remembered safe line with pattern in which it was found
}

void SpecGrep::SetPath(std::filesystem::path path)
{
    try
    {
        std::filesystem::current_path(path);
    }
    catch (...)
    {
        throw;
    }
}

void SpecGrep::outputResultOnConsole()
{
    //1. Get number of files searched, number of files with pattern, number of patterns, path to result and log files, number of used threads, elapsed time
    //2. Pass it to OutputConsole and it should print on console results
}

void SpecGrep::outputResultInFiles()
{
    //1. Get each file path, number of line, line content of pattern it was found 
    //2. Pass it to OutputFile and let it write to file the result and safe as .txt
    //3. Get for each thread file names in which this thread found pattern
    //4. Pass it to OutputFile and let it write to file the result and safe as .log
}