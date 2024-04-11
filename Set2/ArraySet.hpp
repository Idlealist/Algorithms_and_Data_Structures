#pragma once

#include <vector>
#include "Visitor.hpp"

template <typename T>
class Container
{
public:
    Container() {};
public:
    virtual int Count() const = 0;
    virtual bool IsEmpty() const { return Count() == 0; };
    virtual bool IsFull() const = 0;
    virtual void MakeNull() = 0;
    virtual void Accept(Visitor<T>& v) = 0;
};

template <typename T>
class Set : public virtual Container <T>
{
protected:
    int count;
    int universeSize;
public:
    Set(int n) : universeSize(n) {}
    int UniverseSize() const { return universeSize; }
    int Count() const { return count; };
    virtual void Insert(T element) = 0;
    virtual bool IsMember(T element) const = 0;
    virtual void Withdraw(T element) = 0;
};

class SetAsArray : public Set<int>
{
    std::vector<bool> array;
public:
    SetAsArray(unsigned int n) : Set(n) {
        array.resize(n);
        count = 0;
    }
    void MakeNull()//metody z containera
    {
        for (int i = 0; i < (int)array.size(); i++)
            array[i] = false;
        count = 0;
    }
    bool IsFull() const { return (Count() == UniverseSize()); };
    void Insert(int element) {
        if (array[element] == false) {
            array[element] = true;
            count++;
        }
    }
    bool IsMember(int element) const
    {
        return array[element];
    }
    void Withdraw(int element) {
        if (array[element] == true) {
            array[element] = false;
            count--;
        }
    }

    void print() {
        for (int i = 0; i < universeSize * 2 + 1; i++)
            std::cout << "=";
        std::cout << "\n";

        for (int i = 0; i < universeSize; i++)
            std::cout << "|" << i;
        std::cout << "|" << "\n";

        for (int i = 0; i < universeSize; i++)
            std::cout << "|" << (array[i]) ? "T" : "F";
        std::cout << "|" << "\n";

        for (int i = 0; i < universeSize * 2 + 1; i++)
            std::cout << "=";
        std::cout << "\n\n";
    }
    //friend- funkcja uzyska prawo dostepu do prywatnych element�w danej klasy.
    friend SetAsArray operator + (
        SetAsArray const& s, SetAsArray const& t) {
        SetAsArray result(s.UniverseSize());
        for (int i = 0; i < s.UniverseSize(); i++) {
            result.array[i] = s.array[i] || t.array[i];
        }
        return result;
    }
    friend SetAsArray operator - (
        SetAsArray const& s, SetAsArray const& t) {
        SetAsArray result(s.UniverseSize());
        for (int i = 0; i < s.UniverseSize(); i++)
            if (s.array[i])
                result.array[i] = !t.array[i];

        return result;
    }
    friend SetAsArray operator * (
        SetAsArray const& s, SetAsArray const& t) {
        SetAsArray result(s.UniverseSize());
        for (int i = 0; i < s.UniverseSize(); i++) {
            result.array[i] = s.array[i] && t.array[i];
        }
        return result;
    }
    friend bool operator == (
        SetAsArray const& s, SetAsArray const& t) {
        for (int i = 0; i < s.UniverseSize(); i++)
            if (s.array[i] != t.array[i])
                return false;

        return true;
    }
    friend bool operator <= (
        SetAsArray const& s, SetAsArray const& t) {
        for (int i = 0; i < s.UniverseSize(); i++)
            if (s.array[i])
                if (!t.array[i])
                    return false;
        return true;
    }

    void Accept(Visitor<int>& v) {
        for (int i = 0; i < UniverseSize() && !v.IsDone(); ++i)
            if (array[i])
                v.Visit(i);
    };
};

