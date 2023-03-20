#include "utils.h"

std::vector<std::string> get_directories(const std::string& path)
{
    std::vector<std::string> result;
    
    for (const auto & entry : std::filesystem::directory_iterator(path))
        result.push_back(entry.path());

    return result;
}