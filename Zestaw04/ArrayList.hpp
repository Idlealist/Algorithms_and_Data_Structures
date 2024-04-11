#pragma once

#include <iostream>
#include <utility>
#include <stdexcept>

template <int N = 2500>
class ArrayList
{
public:
    void push_front(int x) // Dołącza element na początek listy
    {
        if (full())
            throw std::out_of_range("push_front on full list");
        shift_right(0);
        array[0] = x;
        list_size++;
    }
    int pop_front() // Usuwa i zwraca element z początku listy
    {
        if (empty())
            throw std::out_of_range("pop_front on empty list");
        int ret_val = array[0];
        shift_left(0);
        list_size--;
        return ret_val;
    }
    void push_back(int x) // Dołącza element na koniec listy
    {
        if (full())
            throw std::out_of_range("push_back on full list");
        array[list_size] = x;
        list_size++;
    }
    int pop_back() // Usuwa i zwraca element z końca listy
    {
        if (empty())
            throw std::out_of_range("pop_back on empty list");
        list_size--;
        return array[list_size];
    }
    int size() // Zwraca liczbę elementów w liście
    {
        return list_size;
    }
    bool empty() // Zwraca true gdy lista jest pusta
    {
        return list_size == 0;
    }
    void clear() // Czyści listę
    {
        list_size = 0;
    }
    int find(int x) // Zwraca pozycję pierwszego elementu o wartości x
    {
        for (int i = 0; i < list_size; i++)
        {
            if (array[i] == x)
                return i;
        }
        return -1;
    }
    int erase(int i) // Usuwa i zwraca element na pozycji i
    {
        if (empty())
            throw std::out_of_range("erase on empty list");
        else if (i >= list_size)
            throw std::out_of_range("erase on non-existing position");
        int ret_val = array[i];
        shift_left(i);
        list_size--;
        return ret_val;
    }
    void insert(int i, int x) // Wstawia element x przed pozycję i
    {
        if (full())
            throw std::out_of_range("insert on full list");
        else if (i >= list_size)
            throw std::out_of_range("insert on non-existing position");
        shift_right(i);
        array[i] = x;
        list_size++;
    }
    int remove(int x) // Usuwa wystąpienia x i zwraca ich liczbę
    {
        int count = 0;
        for (int i = 0; i < list_size; i++)
        {
            if (array[i] == x)
            {
                erase(i);
                count++;
            }
        }
        return count;
    }
    bool full()
    {
        return list_size == N;
    }

    bool replace(int x, int y)
    {
        int index = find(x);
        if (index == -1)
            return false;

        array[index] = y;
        return true;
    }

private:
    void shift_right(int index)
    {
        for (int i = list_size; i > index; i--)
            array[i] = array[i - 1];
    }
    void shift_left(int index)
    {
        for (int i = index; i < list_size; i++)
            array[i] = array[i + 1];
    }
    int list_size = 0;
    int array[N];
};