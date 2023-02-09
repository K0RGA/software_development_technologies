
#ifndef LAB1_STACK_H
#define LAB1_STACK_H
#include <iostream>

const int STACK_SIZE = 5;

class Stack {
    int stk[STACK_SIZE]{};
    int top;
public:
    Stack() { top = -1; }
    class Range {
    };

    void push(int variable);

    int pop();

    int& operator[](int index);
};

#endif //LAB1_STACK_H
