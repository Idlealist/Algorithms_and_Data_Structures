#pragma once

template <typename T>
class Visitor
{
    public:
    virtual void Visit (T & element) = 0;
    virtual bool IsDone () const {return false;}
};

class AddingVisitor : public Visitor<int>{
    public:
        void Visit(int& element){
            sum += element;
        }
        void printSum(){
            std::cout << "Visitor sum: " << sum << "\n";
        }
    private:
    int sum = 0;
};

class OddVisitor : public Visitor<int>{
    public:
        OddVisitor();
        void Visit(int& element){
            if(element % 2 == 1)
                odd = true;
        }

        bool isDone(){
            return odd;
        }
    private:
    bool odd = false;
};
