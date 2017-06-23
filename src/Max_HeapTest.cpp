#include "../include/Max_Heap.h"
#include <iostream>

int main() {
    Max_Heap mh(9);

    mh.insert(9);
    mh.insert(9);
    mh.insert(1);
    mh.insert(6);
    mh.insert(9);
    mh.insert(9);
    mh.insert(6);
    mh.insert(6);
    mh.insert(2);
    mh.print();
}