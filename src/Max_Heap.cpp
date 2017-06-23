/**
 * \file Max_Heap.cpp
 *
 * This file contains the Max heap data structure implementation methods.
 *
 * \data Creation: 23/06/2016
 * \data Alteration: 23/06/2016
 * \author Lucas Fonseca dos Santos 
 */
#include "../include/Max_Heap.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Max heap structure object constructor.
 * It set states to capacity, contentHeap and size max heap attributes.
 *
 * \remark It is an overload constructor.
 * \param capacity Integer capacity value passed by the user.
 */
Max_Heap::Max_Heap(int capacity) {
    this->capacity = capacity;
    this->contentHeap = new Data[capacity];
    this->size = 0;
}

/**
 * Max heap structure object constructor.
 * It set states to elementsArray, size and capacity max heap attributes.
 * 
 * \remark It is an overload constructor.
 * \param elementsArray Elements array passed by the user to max heap content.
 * \param size Integer size value.
 * \param capacity Integer capacity value. 
 */
Max_Heap::Max_Heap(Data elementsArray[], int size, int capacity) {
    (capacity == 0)? this->capacity = size : this->capacity = capacity;
    this->contentHeap = new Data[capacity];
    for(int i=0; i<size; i++) {
        contentHeap[i] = elementsArray[i];
        this->size = size;
    }
    arrange();
}

/**
 * Max heap structure object destructor.
 */
Max_Heap::~Max_Heap() {
    delete[] contentHeap;
}

void Max_Heap::arrange() {
    for(int i=(size/2-1); i>=0; i++) {
        arrangeDown(i);
    }
}

inline int Max_Heap::father(int i) {
    return (i-1)/2;
}

inline int Max_Heap::left(int i) {
    return 2*i+1;
}

inline int Max_Heap::right(int i) {
    return 2*i+2;
}

void Max_Heap::arrangeDown(int i) {
    int leftChild = left(i);
    int rightChild = right(i);
    int higher;

    if((leftChild < this->size) && (contentHeap[leftChild] > contentHeap[i])) {
        higher = leftChild;
    }else {
        higher = i;
    }

    if((rightChild < this->size) && (contentHeap[rightChild] > contentHeap[i])){
        higher = rightChild;
    }else {
        higher = i;
    }

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

void Max_Heap::print() {
    for(int i=0; i<this->size; i++) {
        cout << contentHeap[i] << " ";
    }
    cout << "\n";
}

inline Data Max_Heap::getRoot() {
    return contentHeap[0];
}

Data Max_Heap::removeRoot() {
    if(this->size != 0) {
        Data rootElement = contentHeap[0];
        swap(contentHeap[0], contentHeap[this->size - 1]);
        this->size--;
        arrangeDown(0);
        return rootElement;
    }else {
        cout << "erro\n";
        exit(EXIT_FAILURE);
    }
}

void Max_Heap::insert(Data content) {
    if(this->size == this->capacity) {
        cout << "erro\n";
        exit(EXIT_FAILURE);
    }else {
        this->contentHeap[this->size] = content;
        arrangeUp(this->size);
        this->size++;
    }
}