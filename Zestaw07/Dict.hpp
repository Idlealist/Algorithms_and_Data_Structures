#pragma once

#include "LinkedList.hpp"

#include <string>

#define CLASSES 10

template <class K>
unsigned int hash(const K &);
unsigned int hash(const std::string &s)
{
    unsigned int hash = 4135;
    for (const auto i : s)
        hash = (hash << 4) + i;
    return hash % CLASSES;
}

template <class K, class V>
class Dict
{
    using Pair = std::pair<K, V>;

public:
    Dict() {}    // Konstruktor
    void clear() // Czyści słownik
    {
        for (int i = 0; i < CLASSES; i++)
            dict[i].clear();
    }

    bool insert(const Pair &p) // Dodaje parę klucz-wartość do słownika
    {
        unsigned int hashedKey = hash(p.first);
        if (find(p.first))
            for (auto &i : dict[hashedKey])
                if (i.x.first == p.first)
                {
                    i.x.second = p.second;
                    return false;
                }

        dict[hashedKey].push_back(p);
        return true;
    }

    bool find(const K &k) // Sprawdza czy słownik zawiera klucz
    {
        unsigned int hashedKey = hash(k);
        for (const auto &i : dict[hashedKey])
            if (i.x.first == k)
                return true;

        return false;
    }
    V &operator[](const K &k) // Zwraca wartość dla klucza
    {
        unsigned int hashedKey = hash(k);
        for (auto &i : dict[hashedKey])
            if (i.x.first == k)
                return i.x.second;

        Pair tmp;
        tmp.first = k;
        dict[hashedKey].push_back(tmp);
        return dict[hashedKey].get_back().second;
    }
    bool erase(const K &k) // Usuwa parę od danym kluczu
    {
        unsigned int hashedKey = hash(k);
        int n = 0;
        for (auto &i : dict[hashedKey])
        {
            if (i.first == k)
            {
                dict[hashedKey].erase(n);
                return true;
            }
            n++;
        }
        return false;
    }
    int size() // Zwraca liczbę par
    {
        int total = 0;
        for (auto const &i : dict)
            total += i.size();
        return total;
    }
    bool empty() // Sprawdza czy słownik jest pusty
    {
        return (size() == 0) ? true : false;
    }
    void buckets() // Wypisuje informację o słowniku (patrz poniżej)
    {
        int shortest = dict[0].size();
        int longest = shortest;
        for (int i = 0; i < CLASSES; i++)
        {
            if (dict[i].size() > longest)
            {
                longest = dict[i].size();
            }
            else if (dict[i].size() < shortest)
            {
                shortest = dict[i].size();
            }
        }
        std::cout << "# " << size() << " " << CLASSES << " " << shortest << " " << longest << std::endl;
    }

private:
    LinkedList<Pair> dict[CLASSES];
};