#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        T val = v[i];
        int j = i;
        while (val < v[j - 1])
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = val;
    }
}

int main()
{
    int number;
    std::vector<int> numbers;

    while (std::cin >> number)
        numbers.push_back(number);

    auto start = std::chrono::high_resolution_clock::now();

    sort<int>(numbers);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

    for (const auto &i : numbers)
        std::cout << i << std::endl;

    return 0;
}