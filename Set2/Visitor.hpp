#pragma once

template <typename T>
class Visitor
{
public:
    virtual void Visit(T& element) = 0;
    virtual bool IsDone() const { return false; }
};

class AddingVisitor : public Visitor<int> {
public:
    AddingVisitor() {}
    virtual void Visit(int& element) override {
        sum += element;
    }
    void printSum() {
        std::cout << "Visitor sum: " << sum << "\n";
    }
private:
    int sum = 0;
};


class OddVisitor : public Visitor<int> {
public:
    OddVisitor() {
        odd = false;
        lastVisited = 0;
    };
    virtual void Visit(int& element) override {
        lastVisited = element;
        if (element % 2 == 1) 
            odd = true;
    }

    virtual bool IsDone()const override {
        return odd;
    }

    void printLastVisited() {
        std::cout << "Last Visited index: " << lastVisited << "\n";
    }

    void reset() {
        odd = false;
        lastVisited = 0;
    }
private:
    bool odd;
    int lastVisited;
};
