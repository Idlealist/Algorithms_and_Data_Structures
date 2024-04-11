#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#define N 1000000
template <class T>
void sort(std::vector<T> &v)
{

    int max_range = *std::max_element(v.begin(), v.end());
    int min_range = *std::min_element(v.begin(), v.end());
    int range = max_range - min_range + 1;

    T count[N];
    for (int i = 0; i < range; i++)
        count[i] = 0;

    for (size_t i = 0; i < v.size(); i++)
        count[v[i] - min_range]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    std::vector<T> sorted(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
        sorted[--count[v[i] - min_range]] = v[i];

    v = std::move(sorted);
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