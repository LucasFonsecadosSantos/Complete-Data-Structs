#include "../include/Max_Heap.h"
#include <iostream>

int main() {
    Max_Heap mh(20);

    mh.insert(18);
    mh.insert(9);
    mh.insert(15);
    mh.insert(7);
    mh.insert(6);
    mh.insert(10);
    mh.insert(8);
    mh.insert(4);
    mh.insert(5);
    mh.insert(3);
    mh.insert(2);
    mh.insert(5);
    mh.insert(3);
    mh.insert(2);
    mh.insert(6);
    mh.insert(2);
    mh.removeRoot();
    mh.print();
}