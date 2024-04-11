#pragma once

#include <iostream>
#include <chrono>
#include <utility>
#include <stdexcept>
template <class T>
class LinkedList
{ // Klasa listy
public:
    struct Node
    {               // Zagnieżdżona klasa węzła
        T x;        // Element przechowywany przez węzeł listy
        Node *prev; // Wskaźnik do poprzedniego węzła
        Node *next; // Wskaźnik do kolejnego węzła
    };
    LinkedList()
    {
        guard.next = &guard;
        guard.prev = &guard;
        guard.x = 0;
    };
    ~LinkedList()
    {
        while (!empty())
            pop_front();
    };
    void push_front(T x) // Dołącza element na początek listy
    {
        Node *tmp = new Node;
        tmp->x = x;

        tmp->next = guard.next;
        tmp->prev = &guard;

        guard.next->prev = tmp;
        guard.next = tmp;
        guard.x++;
    }
    T pop_front() // Usuwa i zwraca element z początku listy
    {
        if (empty())
            throw std::out_of_range("pop_front() on empty list");
        T ret_val = guard.next->x;
        Node *tmp = guard.next;

        guard.next = tmp->next;
        guard.next->prev = &guard;
        guard.x--;

        delete tmp;
        return ret_val;
    }
    void push_back(T x) // Dołącza element na koniec listy
    {
        Node *tmp = new Node;
        tmp->x = x;

        tmp->prev = guard.prev;
        tmp->next = &guard;

        guard.prev->next = tmp;
        guard.prev = tmp;
        guard.x++;
    }
    T pop_back() // Usuwa i zwraca element z końca listy
    {
        if (empty())
            throw std::out_of_range("pop_back() on empty list");
        T ret_val = guard.prev->x;
        Node *tmp = guard.prev;

        guard.prev = tmp->prev;
        guard.prev->next = &guard;
        guard.x--;

        delete tmp;
        return ret_val;
    }
    int size() // Zwraca liczbę elementów w liście
    {
        return guard.x;
    }
    bool empty() // Zwraca true gdy lista jest pusta
    {
        return size() == 0;
    }
    void clear() // Czyści listę
    {
        while (!empty())
            pop_front();
    }
    int find(T x) // Zwraca pozycję pierwszego elementu o wartości x
    {
        Node *tmp = &guard;

        for (int i = 0; i < size(); i++)
        {
            tmp = tmp->next;

            if (tmp->x == x)
                return i;
        }
        return -1;
    }
    T erase(int i) // Usuwa i zwraca element na pozycji i
    {
        if (i > size())
            throw std::out_of_range("erase in not existing position");

        T ret_val;
        Node *tmp = guard.next;

        while (i--)
            tmp = tmp->next;

        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        ret_val = tmp->x;

        guard.x--;

        delete tmp;
        return ret_val;
    }
    void insert(int i, T x) // Wstawia element x przed pozycję i
    {
        if (i > size())
            throw std::out_of_range("insert before not existing position");

        Node *insert_before = guard.next;
        Node *inserted = new Node;
        while (i--)
            insert_before = insert_before->next;

        inserted->prev = insert_before->prev;
        inserted->next = insert_before;
        inserted->prev->next = inserted;
        insert_before->prev = inserted;
        inserted->x = x;
        guard.x++;
    }
    int remove(T x) // Usuwa wystąpienia x i zwraca ich liczbę
    {
        int count = 0;
        int i = -1;
        while ((i = find(x)) != -1)
        {
            erase(i);
            count++;
        }
        return count;
    }
    bool replace(T x, T y) // zastepuje pierwsze wystapienie x przez wartosc y
    {
        int i = find(x);
        if (i == -1)
            return false;
        erase(i);
        insert(i, y);

        return true;
    }

private:
    Node guard; // Wskaźniki do pierwszego i ostatniego węzła
};
