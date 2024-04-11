#include <iostream>
#include "LinkedQueue.hpp"

int main(int argc, char *argv[])
{
    int operation_count = 0;
    Queue<int, 10000> queue;

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
            queue.push(value);
            break;

        case 'D':
            if (!queue.empty())
                std::cout << queue.pop() << std::endl;
            else
                std::cout << "EMPTY" << std::endl;
            break;

        case 'S':
            std::cout << queue.size() << std::endl;
            break;
        }
        operation_count--;
    }
    return 0;
}