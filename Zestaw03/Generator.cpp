#include <iostream>
#include <time.h>

#define MAX_VAL 1000000
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = std::atoi(argv[1]);

    std::cout << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        switch (rand() % 6)
        {
        case 0:
            std::cout << "F " << rand() % (MAX_VAL + 1) << std::endl;
            break;
        case 1:
            std::cout << "B " << rand() % (MAX_VAL + 1) << std::endl;
            break;
        case 2:
            std::cout << "f" << std::endl;
            break;
        case 3:
            std::cout << "b" << std::endl;
            break;
        case 4:
            std::cout << "R " << rand() % (MAX_VAL + 1) << ' ' << rand() % (MAX_VAL + 1) << std::endl;
            break;
        case 5:
            std::cout << "S" << std::endl;
            break;
        }
    }
    return 0;
}