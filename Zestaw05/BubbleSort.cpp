#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    int operation_counter = 0;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        for (size_t j = v.size() - 1; j > i; j--)
        {
            operation_counter++;
            if (v[j - 1] > v[j])
            {
                std::swap(v[j - 1], v[j]);
                operation_counter++;
            }
        }
    }
    std::cerr << "Operations done:" << operation_counter << "\n";
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