#include "../../include/static_structures/Max_Heap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    Max_Heap<int> mh(20);

    mh.insert(9);
    //mh.removeRoot();
    mh.print();
}