#include "ArrayStack.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    Stack<char> operators;
    bool prev_char_is_space = true;
    while (char c_input=getchar())
    {
        switch (c_input)
        {
        case ' ':
            if (!prev_char_is_space)
            {
                std::cout << c_input;
                prev_char_is_space = true;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            operators.push(c_input);
            break;

        case ')':
            std::cout << operators.pop();
            prev_char_is_space = false;
            break;

        default:
            if (isdigit(c_input))
            {
                std::cout << c_input;
                prev_char_is_space = false;
            }

            break;
        }
    }
    std::cout<<std::endl;
    return 0;
}