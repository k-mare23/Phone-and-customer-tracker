#ifndef stack_h
#define stack_h
#include <iostream>
#include <string>
using namespace std;

class stack {
private:
    int top = 0;
    int stack[50];
public:
    void push(int value) {
        if (top > 50) {
            return;
        }
        stack[++top] = value;
    }
    int pop() {
        if (top < 0) {
            return -1;
        }
        int topVal = stack[top];
        top--;
        return topVal;
    }
    int peek() {
        if (top < 0) {
            return -1;
        }
        else {
            int topVal = stack[top];
            return topVal;
        }
    }
    bool isEmpty() {
        return (top <= 0);
    }
};

#endif
