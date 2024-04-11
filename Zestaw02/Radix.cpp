#include <iostream>
#include <vector>
#include "ArrayQueue.hpp"

#define ROZMIAR 1000000
using namespace std;
void radix(vector<int> &v)
{
    Queue<int, ROZMIAR> queues[10];
    int row = 1;
    int digits = (int)v.size();
    int sorted_dig = 0;
    while (sorted_dig < digits)
    {
        for (const auto &i : v)
        {
            queues[(i / row) % 10].push(i);
        }

        sorted_dig = queues[0].size();
        v.clear();

        for (auto &i : queues)
        {
            while (!i.empty())
            {
                v.push_back(i.pop());
            }
        }
        row *= 10;
    }
}

int main()
{

    int input;
    vector<int> v;

    while (std::cin >> input)
    {
        v.push_back(input);
    }

    radix(v);

    for (const auto &i : v)
        std::cout << i << std::endl;
}