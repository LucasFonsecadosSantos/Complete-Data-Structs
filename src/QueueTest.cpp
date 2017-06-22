/**
 * \file QueueTest.cpp
 *
 * This file contains queue tests.
 *
 * \date Creation: 22/06/2017
 * \date Alteration: 22/06/2017
 * \author Lucas Fonseca dos Santos
 */
#include <string>
#include <iostream>
#include "../include/Queue.h"

using namespace std;

int main() {
    Queue q;
    cout << q.enqueue(9) << endl;
    cout << q.enqueue(9) << endl;
    cout << q.enqueue(1) << endl;
    cout << q.enqueue(6) << endl;
    cout << q.enqueue(9) << endl;
    cout << q.enqueue(9) << endl;
    cout << q.enqueue(6) << endl;
    cout << q.enqueue(6) << endl;
    cout << q.enqueue(2) << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << "\n+---------------------+\n";
    cout << q.print() << endl;
    return 0;
}