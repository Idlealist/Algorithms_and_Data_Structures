#pragma once

#include <iostream>
#include <utility>
#include <stdexcept>
template <int N = 2500>
class CursorList
{ // Klasa listy

public:
    CursorList()
    {
        for (int i = 0; i < N; i++)
            arr[i].next = i + 1;
        head = 0;
        tail = 0;
        list_size = 0;
        spare = 0;
    }
    void push_front(int x) // Dołącza element na początek listy
    {
        if (full())
            throw std::out_of_range("push_front on full list");
        int tmp = head;
        head = spare;
        spare = arr[spare].next;
        arr[head].x = x;
        arr[head].next = tmp;
        list_size++;
    }
    int pop_front() // Usuwa i zwraca element z początku listy
    {
        if (empty())
            throw std::out_of_range("pop_front on empty list");
        int tmp = head;
        head = arr[head].next;
        arr[tmp].next = spare;
        spare = tmp;
        list_size--;
        if (empty())
        {
            spare = head;
            tail = head;
        }
        return arr[tmp].x;
    }
    void push_back(int x) // Dołącza element na koniec listy
    {
        if (full())
            throw std::out_of_range("push_back on full list");
        int tmp = tail;
        tail = spare;
        spare = arr[spare].next;
        arr[tmp].next = tail;
        arr[tail].x = x;
        list_size++;
    }
    int pop_back() // Usuwa i zwraca element z końca listy
    {
        if (empty())
            throw std::out_of_range("pop_back on empty list");
        int tmp = head;

        for (int i = 0; i < list_size - 2; i++)
            tmp = arr[tmp].next;

        arr[tail].next = spare;
        spare = tail;
        tail = tmp;
        list_size--;

        return arr[spare].x;
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
        while (!empty())
            pop_front();
    }

    int find(int x) // Zwraca pozycję pierwszego elementu o wartości x
    {
        int tmp = head;
        for (int i = 0; i < list_size; i++)
        {
            if (arr[tmp].x == x)
            {
                return i;
            }
            tmp = arr[tmp].next;
        }
        return -1;
    }

    int erase(int i) // Usuwa i zwraca element na pozycji i
    {
        if (empty())
            throw std::out_of_range("erase on empty list");
        else if (i >= list_size)
            throw std::out_of_range("erase on non-existing position");
        if (i == 0)
        {
            return pop_front();
        }
        int before = head;
        for (int j = i; j > 1; j--)
            before = arr[before].next;
        int erased = arr[before].next;
        arr[before].next = arr[erased].next;
        arr[erased].next = spare;
        spare = erased;

        list_size--;
        return arr[spare].x;
    }
    void insert(int i, int x) // Wstawia element x przed pozycję i
    {
        if (full())
            throw std::out_of_range("insert on full list");
        else if (i >= list_size)
            throw std::out_of_range("insert on non-existing position");

        if (i == 0)
        {
            push_front(x);
        }
        else
        {
            int before = head;

            for (int j = i; j > 1; j--)
                before = arr[before].next;

            int tmp = spare;
            spare = arr[spare].next;
            arr[tmp].next = arr[before].next;
            arr[before].next = tmp;
            arr[tmp].x = x;
            list_size++;
        }
    }

    int remove(int x) // Usuwa wystąpienia x i zwraca ich liczbę
    {
        int count = 0;
        int tmp = head;
        for (int i = 0; i < list_size; i++)
        {
            if (arr[tmp].x == x)
            {
                erase(i);
                count++;
            }
            tmp = arr[tmp].next;
        }
        return count;
    }

    bool replace(int x, int y)
    {

        int position = find(x);
        if (position == -1)
            return false;

        erase(position);
        insert(position, y);
        return true;
    }

    bool full()
    {
        return list_size == N;
    }


private:
    struct Node
    {             // Zagnieżdżona klasa węzła
        int x;    // Element przechowywany przez węzeł listy
        int next; // Indeks kolejnego węzła
    };
    Node arr[N];   // Tablica węzłów
    int head;      // Indeks pierwszego węzła
    int tail;      // Indeks ostatniego węzła
    int list_size; // Rozmiar listy
    int spare;     // Indeks pierwszego nieużytego elementu tablicy
};