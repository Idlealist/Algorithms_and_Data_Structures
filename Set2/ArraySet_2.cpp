// ArrSet.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <iomanip>

#include "ArraySet.hpp"

#define UNI_SIZE 10

int main()
{
    SetAsArray A(UNI_SIZE), B(UNI_SIZE), C(UNI_SIZE), D(UNI_SIZE);
    for (int i = 0; i < UNI_SIZE; i++)
    {
        if (i % 2 == 0)
            A.Insert(i);
        else
            B.Insert(i);
    }
    C = A + B;
    D = C - B;

    std::cout << std::setw(UNI_SIZE + 2) << "A\n";
    A.print();
    std::cout << std::setw(UNI_SIZE + 2) << "B\n";
    B.print();
    std::cout << std::setw(UNI_SIZE + 2) << "C\n";
    C.print();
    std::cout << std::setw(UNI_SIZE + 2) << "D\n";
    D.print();
    std::cout << "D==A " << ((D == A) ? "True" : "False") << "\n" <<
        "D<=A " << ((D <= A) ? "True" : "False") << "\n" <<
        "C==B " << ((C == B) ? "True" : "False") << "\n" <<
        "B<=C " << ((B <= C) ? "True" : "False") << "\n";


    A.Insert(1);
    std::cout << std::setw(UNI_SIZE + 2) << "A\n";
    A.print();
    std::cout << "D==A " << ((D == A) ? "True" : "False") << "\n" <<
        "D<=A " << ((D <= A) ? "True" : "False") << "\n";

    std::cout << "\n<<<<<<<< Test 2.1 >>>>>>>>\n\n";
    A.Insert(5);
    std::cout << std::setw(UNI_SIZE + 2) << "A\n";
    A.print();
    AddingVisitor v_A;
    A.Accept(v_A);
    v_A.printSum();

    SetAsArray E = A * B;
    AddingVisitor v_E;
    E.Accept(v_E);
    std::cout << std::setw(UNI_SIZE + 2) << "E\n";
    E.print();
    v_E.printSum();

    std::cout << "\n<<<<<<<< Test 2.2 >>>>>>>>\n\n";

    OddVisitor oV;
    std::cout << std::setw(UNI_SIZE + 2) << "B\n";
    B.print();
    B.Accept(oV);
    std::cout << "Set B has odd number " << (oV.IsDone() ? "True" : "False") << "\n";
    oV.printLastVisited();
    oV.reset();

    std::cout << std::setw(UNI_SIZE + 2) << "A\n";
    A.print();
    A.Accept(oV);
    std::cout << "Set A has odd number " << (oV.IsDone() ? "True" : "False") << "\n";
    oV.printLastVisited();
    oV.reset();

    A.Withdraw(1);
    A.Withdraw(5);

    std::cout << std::setw(UNI_SIZE + 2) << "A\n";
    A.print();
    A.Accept(oV);
    std::cout << "Set A has odd number " << (oV.IsDone() ? "True" : "False") << "\n";
    oV.printLastVisited();
}

