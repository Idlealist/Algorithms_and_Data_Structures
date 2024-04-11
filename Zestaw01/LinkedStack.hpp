#pragma once

#include <iostream>
#include <chrono>
#include <utility>
#include <stdexcept>

template <class T, int N = 1000000>
class Stack
{
public:
    struct Node
    {
        T value;
        Node* previous;
    };

    Stack(){}
    ~Stack()
    {
        while (!this->empty())
            this->pop();
    }
    template <class U> // Uniwersalne referencje
    void push(U &&x)   // Wstawia element x na stos
    {
        if (height == N)     
            throw std::out_of_range("Push when stack is full");
        Node *tmp = new Node; 
        tmp->previous = m_Stack;
        tmp->value = x;
        m_Stack = tmp;
        height++;
    }

    T pop() // Usuwa element ze stosu i zwraca jego wartość
    {
        if (empty())
            throw std::out_of_range("Pop when stack is empty");
        T return_val = m_Stack->value;
        Node *prev_node = m_Stack->previous; 
        delete m_Stack;
        m_Stack = prev_node;
        height--;
        return return_val;
    }

    T &top() // Zwraca referencję do najmłodszego elementu
    {
        return m_Stack; 
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
    Node* m_Stack = nullptr;
    int height = 0;
};