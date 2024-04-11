#include "PriorityQueue.hpp"

BinaryHeap<int> queue(2);

void printIsEmpty(bool b)
{
    if (b)
        std::cout << "Kolejka jest pusta \n";
    else
        std::cout << "Kolejka nie jest pusta \n";
}

void WypiszMin()
{
    std::cout << "Obecne minimum:" << queue.FindMin() << std::endl;
}

void Enqueue(int a)
{
    queue.Enqueue(a);
    std::cout << "Enqued " << a << std::endl;
}

void Wypisz()
{
    queue.print();
}

void DequeueMin()
{
    queue.DequeueMin();
    std::cout<<"DequeueMin()\n";
}

void Makenull()
{
    queue.MakeNull();
    std::cout<<"MakeNull()\n";
}

int main(int argc, char const *argv[])
{

    printIsEmpty(queue.IsEmpty());
    Enqueue(5);
    printIsEmpty(queue.IsEmpty());
    Wypisz();
    WypiszMin();
    Enqueue(6);
    Wypisz();
    WypiszMin();
    Enqueue(8);
    Wypisz();
    WypiszMin();
    Enqueue(3);
    Wypisz();
    WypiszMin();
    Enqueue(9);
    Wypisz();
    WypiszMin();
    Enqueue(2);
    Wypisz();
    WypiszMin();
    Enqueue(1);
    Wypisz();
    WypiszMin();
    DequeueMin();
    Wypisz();
    WypiszMin();
    DequeueMin();
    Wypisz();
    WypiszMin();
    Makenull();
    printIsEmpty(queue.IsEmpty());
    return 0;
}
