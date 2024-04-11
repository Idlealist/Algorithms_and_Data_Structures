#pragma once

#include <utility>
#include <stdexcept>

template <class T, int N = 1000000>
class Stack
{
public:
    Stack()
    {
        m_Stack = new T[N];
    }
    ~Stack()
    {
        delete[] m_Stack;
    }
    template <class U> // Uniwersalne referencje
    void push(U &&x)   // Wstawia element x na stos
    {
        if (height == N)
            throw std::out_of_range("Push when stack is full");

        m_Stack[height++] = x;
    }
    T pop() // Usuwa element ze stosu i zwraca jego wartość
    {
        if (empty())
            throw std::out_of_range("Pop when stack is empty");
        return m_Stack[--height];
    }
    T &top() // Zwraca referencję do najmłodszego elementu
    {
        if (empty())
            throw std::out_of_range("Top when stack is empty");
        return m_Stack[height - 1]; 
    }
    int size() // Zwraca liczbę elementów na stosie
    {
        return height;
    }
    bool empty() // Sprawdza czy stos jest pusty
    {
        return height == 0;
    }

private:
    T* m_Stack;
    int height = 0;
};