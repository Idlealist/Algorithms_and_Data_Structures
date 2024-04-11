#include <iostream>
#include <time.h>
int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    int max_val = atoi(argv[2]);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        std::cout << (rand() % max_val) + 1 << std::endl;
    }

    return 0;
}