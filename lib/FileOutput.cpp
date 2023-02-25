#include "FileOutput.hpp"

void FileOutput::outputResult(std::string resultFileName, std::vector<Files> allFiles)
{
    std::ofstream resultFile(resultFileName);
    for(int i = 0; i < allFiles.size(); i++)
    {
        resultFile << allFiles[i].filePath << ':' << allFiles[i].line << ": " << allFiles[i].lineWithPattern << "\n";
    }
}

void FileOutput::outputLog(std::string logFileName, std::vector<Files> allFiles)
{
    std::ofstream resultFile(logFileName);

    //druga pętla teraz do log file powinna usunąć wziąć tylko nazwę pliku i przypisać do threadsów odpowiedzialnych za tego file'a
}