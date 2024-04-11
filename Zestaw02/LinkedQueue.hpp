#pragma once

#include <iostream>
#include <chrono>
#include <utility>
#include <stdexcept>
template <class T, int N>
class Queue
{
public:
    struct Node
    {
        T value;
        Node *next;
    };

    Queue() {}
    ~Queue()
    {
        while (!empty())
            pop();
    }

    template <class U> // Uniwersalne referencje
    void push(U &&x)   // Wstawia element x do kolejki (takze enqueue)
    {
        if (length == N)
            throw std::out_of_range("push when queue is full");

        Node *tmp = new Node;
        tmp->value = std::forward<U>(x);

        if (length == 0)
        {
            tail = tmp;
            head = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

        length++;
    }

    T pop() // Usuwa element ze stosu i zwraca jego wartość
    {

        if (empty())
            throw std::out_of_range("read when queue is empty");

        T return_val = head->value;
        Node *tmp = head->next;
        delete head;
        head = tmp;
        length--;
        return return_val;
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
    Node *head, *tail;
    int length = 0;
};
