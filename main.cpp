#include <iostream>
#include <string>
#include "stack.h"
#include "Queue.h"
using namespace std;
stack s;
Queue q;

void pushedElementsOperation(int track, int cycle) { //goes through the values in the stack that were pushed only
    while (!s.isEmpty()) {
        int p = s.peek(); //phone
        int c = q.inFront(); //customer
        if (p == c) {
            q.del();
            s.pop();
            cycle = 0; //cycle starts over again
            track--; //one less value to track
        }
        else {
            int temp = q.inFront(); //delete front member and put to rear
            q.insert(temp);
            q.del();
            cycle++; //adds one cycle since had no matching value in this iteration
        }
        if (cycle == track) { //if made a full circle, and arrived to beginning w/o any removals from queue/stack
            break;
        }
    }
    if (!s.isEmpty()) { //not all customers got a phone
        cout << track << " customer(s) did not get a phone." << endl;
        return;
    }
    else //all customers got a phone
        cout << "Every customer was able to get a phone." << endl;
}

void operate(int count, int track) { //goes through original stack before any pushing to rear
    while (!s.isEmpty()) {
        int p = s.peek() - 48; //phone
        int c = q.inFront() - 48; //customer
        if (p == c) { //if top of stack == front of queue, pop both values
            s.pop();
            q.del();
        }
        else {
            int temp = q.inFront(); //delete front member and put to rear
            q.insert(temp);
            q.del();
            track++; //keeps track of any pushed values to the end of queue
        }
        
        count--;
        if (count == 0) { //meaning we reached end of orignal queue before any pushing to rear
            break;
        }
    }
    if (!s.isEmpty())
        pushedElementsOperation(track, 0); //operate now only on customers that didn't get a phone
    else {
        cout << "Every customer was able to get a phone." << endl;
    }
}
stack reverseStack(stack& s) { //reverses stack so first value in list on top
    stack t;
    while (!s.isEmpty()) {
        int temp = s.pop();
        t.push(temp);
    }
    return t;
}
int main() {
    string customers;
    string phones;
    getline(cin, customers);
    int count = 0;
    for (int i = 0; i < customers.length(); i++) {
        if (customers[i] == ' ')
            continue;
        else {
            count++;
            q.insert(customers[i]);
        }
    }
    getline(cin, phones);
    for (int i = 0; i < phones.length(); i++) {
        if (phones[i] == ' ')
            continue;
        else
            s.push(phones[i]);
    }
    s = reverseStack(s);
    operate(count,0);
    return 0;
}
