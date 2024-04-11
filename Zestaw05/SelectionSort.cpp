#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        size_t min_pos = i;
        for (size_t j = i; j < v.size(); j++)
        {
            if (v[j] < v[min_pos])
                min_pos = j;
        }
        std::swap(v[i], v[min_pos]);
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