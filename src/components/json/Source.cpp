#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>



int trash() { // пример использования джонсона
    nlohmann::json j{};
    std::fstream file;
    std::string path = "src\\components\\json\\Source.json";
    file.open(path, std::fstream::in);
    file >> j;
    std::string zalupa = j["zombies"]["zombie-usual"]["assets"][2];
    std::cout << zalupa << std::endl;
    system("pause");

}