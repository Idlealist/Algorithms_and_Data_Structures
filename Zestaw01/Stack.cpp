#include <iostream>
#include "ArrayStack.hpp"

int main(int argc, char *argv[])
{
    int operation_count = 0;
    Stack<int> stack;

    std::cin >> operation_count;

    while (operation_count)
    {
        char operation_code;
        int value;
        std::cin >> operation_code;
        switch (operation_code)
        {
        case 'A':
            std::cin >> value;
            stack.push(value);
            break;

        case 'D':
            if (!stack.empty())
                std::cout << stack.pop() << std::endl;
            else
                std::cout << "EMPTY" << std::endl;
            break;

        case 'S':
            std::cout << stack.size() << std::endl;
            break;
        }
        operation_count--;
    }
    return 0;
}