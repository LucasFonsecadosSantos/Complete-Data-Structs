#include "../include/Max_Heap.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

Max_Heap::Max_Heap(int capacity) {
    this->capacity = capacity;
    this->contentHeap = new Data[this->capacity];
    this->size = 0;
}

Max_Heap::Max_Heap(Data elementsArray[], int size, int capacity) {
    (capacity > 0)? this->capacity = capacity : this->capacity = size;
    this->size = size;
    this->contentHeap = new Data[this->capacity];
    for(int i=0; i<this->size; i++) {
        contentHeap[i] = elementsArray[i];
    }
    arrange();
}

Max_Heap::~Max_Heap() {
    delete[] contentHeap;
}

void Max_Heap::arrange() {
    for(int i=(size/2-1); i>=0; i--)
        arrangeDown(i);
}

inline int Max_Heap::father(int i) {
    return (i-1)/2;
}

inline int Max_Heap::left(int i) {
    return (2*i+1);
}

inline int Max_Heap::right(int i) {
    return (2*i+2);
}

void Max_Heap::arrangeDown(int i) {
    int leftChild = left(i);
    int rightChild = right(i);
    int higher;

    if((leftChild < this->size) && (contentHeap[i] < contentHeap[leftChild]))
        higher = leftChild;
    else
        higher = i;
    
    if((rightChild < this->size) && (contentHeap[i] < contentHeap[rightChild]))
        higher = rightChild;
    else
        higher = i;
    
    if(i != higher) {
        swap(contentHeap[i], contentHeap[higher]);
        arrangeDown(higher);
    }
}

void Max_Heap::arrangeUp(int i) {
    int f = father(i);

    if(contentHeap[i] > contentHeap[f]) {
        swap(contentHeap[i], contentHeap[f]);
        arrangeUp(f);
    }
}

inline Data Max_Heap::getRoot() {
    return this->contentHeap[0];
}

Data Max_Heap::removeRoot() {
    if(this->size > 0) {
        Data rootElement = this->contentHeap[0];
        swap(contentHeap[0], contentHeap[this->size-1]);
        this->size--;
        arrangeDown(0);
        return rootElement;
    }else {
        cout << "erro";
        exit(EXIT_FAILURE);
    }
}

void Max_Heap::insert(Data content) {
    if(this->size <= this->capacity) {
        this->contentHeap[this->size] = content;
        arrangeUp(this->size);
        this->size++;
    }else {
        cout << "erro";
        exit(EXIT_FAILURE);
    }
}

void Max_Heap::print() {
    int i = 0;
    int h = (log((this->size+1)) * 1.44269504088896340736) + 1;
    cout << h << "levels. \n";
    for(int i=1; i<=4; i++) {
        for(int )
    }
}