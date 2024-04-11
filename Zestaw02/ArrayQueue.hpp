#pragma once

#include <utility>
#include <stdexcept>

template <class T, int N>
class Queue
{

public:
    Queue() // Konstruktor domyslny
    {
        queue = new T[N];
    }

    ~Queue()
    {
        delete[] queue;
    }

    template <class U> // Uniwersalne referencje
    void push(U &&x)   // Wstawia element x do kolejki (takze enqueue)
    {
        if (length == N)
            throw std::out_of_range("push when queue is full");

        queue[write] = std::forward<U>(x);
        write++;
        write %= N;
        length++;
    }

    T pop() // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    {
        if (empty())
            throw std::out_of_range("read when queue is empty");

        read++;
        read %= N;
        length--;
        return queue[read];
    }

    int size() // Zwraca liczbe elementów w kolejce
    {
        return length;
    }

    bool empty() // Sprawdza czy kolejka jest pusta
    {
        return length == 0;
    }

private:
    T *queue;
    int read = N - 1;
    int write = 0;
    int length = 0;
};
