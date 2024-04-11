#include "Dict.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    Dict<std::string, std::string> dict;
    std::string key, val;
    if (argc < 2)
        return 3;
    std::ifstream file(argv[1]);

    while (file >> key)
    {
        file >> val;
        dict.insert({key, val});
    }

    while (std::cin >> key)
    {
        if (dict.find(key))
            std::cout << dict[key] << std::endl;
        else
            std::cout << '-' << std::endl;
    }

    file.close();
    return 0;
}
