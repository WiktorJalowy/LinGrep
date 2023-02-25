#include <cstring>
#include "lib/SpecGrep.hpp"

int main(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string pattern = argv[1];
    std::string path = ".";
    std::string log = "SpecGrep.log";
    std::string result = "SpecGrep.txt";
    int threadsNum = 4;
    SpecGrep grep;
    for(int i = 2; i < argc; i++)
    {
        if(std::strcmp(argv[i], "-d") == 0 || std::strcmp(argv[i], "-dir") == 0)
        {
            path = argv[i + 1];
            std::cout << path << std::endl;
        }
        else if(std::strcmp(argv[i], "-l") == 0|| std::strcmp(argv[i], "--log_file") == 0)
        {
            log = argv[i + 1];
        }
        else if(std::strcmp(argv[i], "-r") == 0|| std::strcmp(argv[i], "--result_file") == 0)
        {
            result = argv[i + 1];
        }
        else if(std::strcmp(argv[i], "-t") == 0|| std::strcmp(argv[i], "--threads") == 0)
        {
            threadsNum = atoi(argv[i + 1]);
        }
    }
    grep.searchFor(pattern, path, log, result, threadsNum);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSeconds = end-start;
    std::cout << "Elapsed time: " << elapsedSeconds.count() << "s" << std::endl;
}