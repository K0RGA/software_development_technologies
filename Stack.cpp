#include "Stack.h"

int Stack::pop() {
    if (top < 0)
        throw Range();
    return stk[top--];
}

void Stack::push(int variable) {
    if (top >= STACK_SIZE - 1) {
        throw Range();
    }
    stk[++top] = variable;
}

int &Stack::operator[](int index){
    try {
        if (index > STACK_SIZE) throw index;
        return stk[index];
    } catch (int){

        std::cerr << std::endl << "Out of range";
        exit(1);
    }
}

