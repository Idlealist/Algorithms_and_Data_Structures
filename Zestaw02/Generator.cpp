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
        switch (rand() % 3)
        {
        case 0:
            std::cout << "A " << rand() % (MAX_VAL + 1) << std::endl;
            break;
        case 1:
            std::cout << "D" << std::endl;
            break;
        case 2:
            std::cout << "S" << std::endl;
        }
    }
    return 0;
}