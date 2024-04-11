#include <iostream>
#include "CursorList.hpp"

int main(int argc, char *argv[])
{
    int operation_count = 0;
    CursorList<2500> list;

    std::cin >> operation_count;

    while (operation_count)
    {
        char operation_code;
        int value, value_2;
        std::cin >> operation_code;
        switch (operation_code)
        {
        case 'F':
            std::cin >> value;
            list.push_front(value);
            break;
        case 'B':
            std::cin >> value;
            list.push_back(value);
            break;
        case 'f':
            if (!list.empty())
                std::cout << list.pop_front() << std::endl;
            else
                std::cout << "EMPTY" << std::endl;
            break;
        case 'b':
            if (!list.empty())
                std::cout << list.pop_back() << std::endl;
            else
                std::cout << "EMPTY" << std::endl;
            break;
        case 'R':
            std::cin >> value >> value_2;
            if (list.replace(value, value_2))
                std::cout << "TRUE" << std::endl;
            else
                std::cout << "FALSE" << std::endl;
            break;
        case 'S':
            std::cout << list.size() << std::endl;
            break;
        }
        operation_count--;
    }
    return 0;
}