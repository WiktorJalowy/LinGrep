#include "SpecGrep.hpp"

void SpecGrep::searchFor(std::string pattern, std::string path, std::string log, std::string result, int threads)
{
    std::filesystem::path dir = path;
    SetPath(dir);

    std::ifstream file;
    std::string line;
    int numOfFilesWithPatterns = 0;
    int numOfFiles = 0;
    int numOfPatterns = 0;
    int numOfHelpPatterns = 0;
    int lineNum = 0;
    std::string tempstr;
    Files patternFound;

    for (const auto &dir_entry : std::filesystem::recursive_directory_iterator("."))
    {
        if(!dir_entry.is_regular_file()) continue;
        file.open(dir_entry.path());
        lineNum = 0;
        while(std::getline(file, line))
        {
            if(line.find(pattern) != std::string::npos)
            {
                numOfPatterns++;
                patternFound.line = lineNum + 1;
                patternFound.lineWithPattern = line;
                patternFound.filePath = std::filesystem::absolute(dir);
                tempstr = dir_entry.path();
                tempstr = tempstr.substr(tempstr.find(".") + 1);
                patternFound.filePath += tempstr;
                filesWithPattern.push_back(patternFound);
            }
            lineNum++;
        }
        if(numOfHelpPatterns != numOfPatterns) 
        {
            numOfHelpPatterns = numOfPatterns;
            numOfFilesWithPatterns++;
        }
        numOfFiles++;
        file.close();
    }
    
    fo.outputResult(result, getFiles());

    for(int i = 0; i < filesWithPattern.size(); i++)
    {
        if(filesWithPattern[i].filePath.find('/') != std::string::npos)
        {
            filesWithPattern[i].filePath = filesWithPattern[i].filePath.substr(filesWithPattern[i].filePath.find('/') + 1);
            i--;
        }
        else
        {
            continue;
        }
    }

    //fo.outputLog(log, getFiles());
    co.outputResults(numOfFiles, numOfFilesWithPatterns, numOfPatterns, result, log, threads);
}

void SpecGrep::SetPath(std::filesystem::path path)
{
    try
    {
        std::filesystem::current_path(path);
    }
    catch(...)
    {
        std::cerr << "Wrong input please insert a existing path!";
    }
}

std::vector<Files> SpecGrep::getFiles()
{
    return filesWithPattern;
}