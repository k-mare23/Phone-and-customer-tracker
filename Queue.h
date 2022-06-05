#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;

const int n = 50;

class Queue {
private:
    int queue[n];
    int front = -1, rear = -1;
public:
    void insert(int value) {
        if (rear == n - 1) {
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
    void del() {
        if (front == -1 || front > rear) {
            return;
        }
        else {
            front++;
        }
    }
    void display() {
        if (front == -1) {
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    int inFront() { //returns first person in Queue 
        if (front >= 0) {
            return queue[front];
        }
        else {
            cout << "Empty" << endl;
            return -1;
        }
    }
};

#endif
