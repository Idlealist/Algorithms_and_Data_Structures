#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Container
{
protected:
    Container(){};

public:
    virtual unsigned int Count() const = 0;
    virtual bool IsEmpty() const { return Count() == 0; };
    virtual bool IsFull() const = 0;
    virtual void MakeNull() = 0;
};

template <typename T>
class PriorityQueue : public Container
{
public:
    virtual void Enqueue(T element) = 0;
    virtual T FindMin() const = 0;
    virtual T DequeueMin() = 0;
};

template <typename T>
class BinaryHeap : public PriorityQueue<T>
{
protected:
    int count;
    std::vector<T> data;

    int lChildInd(int i)
    {
        return 2 * i + 1;
    }

    int rChildInd(int i)
    {
        return 2 * i + 2;
    }

    int parentInd(int i)
    {
        return (i - 1) / 2;
    }
    bool isLeaf(int i)
    {
        return i < count;
    }
    int indOfMin(int i)
    {
        int l = lChildInd(i);
        int r = rChildInd(i);
        if (!isLeaf(l))
            return i;
        else if (!isLeaf(r))
            return (data[l] < data[i]) ? l : i;
        else
        {
            int min = (data[l] < data[r]) ? l : r;
            return (data[min] < data[i]) ? min : i;
        }
    }

public:
    BinaryHeap(unsigned int n)
    {
        count = 0;
        data.resize(n);
    }
    ~BinaryHeap() { ; };
    void MakeNull()
    {
        count = 0;
    }
    void Enqueue(T element)
    {
        if (IsFull())
            data.resize((size_t)count + 1);

        int current = count;
        data[current] = element;

        while (current > 0 && data[parentInd(current)] > element)
        {
            std::swap(data[parentInd(current)], data[current]);
            current = parentInd(current);
        }
        count++;
    }
    T FindMin() const
    {
        if (IsEmpty())
            throw std::out_of_range("Find min on an empty queue");
        else
            return data[0];
    }
    T DequeueMin()
    {
        if (IsEmpty())
            throw std::out_of_range("DequeueMin on an empty queue");

        std::swap(data[--count], data[0]);
        int current = 0;
        int lower;
        while ((lower = indOfMin(current)) != current)
        {
            std::swap(data[current], data[lower]);
            current = lower;
        }

        return data[count];
    }
    bool IsEmpty() const
    {
        return count == 0;
    }
    bool IsFull() const
    {
        return count == (int)data.size();
    }
    unsigned int Count() const { return count; }

    void print()
    {
        if (IsEmpty())
            std::cout << "Queue is empty\n";
        std::cout << "<=================================\n"
                  << "Queue count : " << Count() << std::endl;

        int depth = log2(count) + 1;
        int level = 1;

        for (int i = 0; i < count; i++)
        {
            int gap;
            if (pow(2, level - 1) - 1 == i)
            {
                gap = ((depth - level) * 2) - 1;
            }
            else
            {
                gap = ((depth - level) * 2) + 1;
            }

            std::cout << std::setw(gap + floor(log10(data[i])) + 1) << data[i];
            if (pow(2, level) - 2 == i)
            {
                std::cout << std::endl;
                level++;
            }
        }
        std::cout << "\n=================================>\n";
    }
};