/**
 * \file Max_Heap.cpp
 *
 * This file contains a max heap data structure implementation
 * methods. This algorithm was implemented using generic programming.
 *
 * \date Creation: 23/06/2017
 * \date Alteration: 23/06/2017
 * \author Lucas Fonseca dos Santos
 */
#include "../../include/static_structures/Max_Heap.h"
#include <string>

using namespace std;

/**
 * 
 */
template<class TYPE>
Max_Heap<TYPE>::Max_Heap(int capacity) {
    this->capacity = capacity;
    this->contentHeap = new TYPE[capacity];
    this->size = 0;
}

/**
 * 
 */
template<class TYPE>
Max_Heap<TYPE>::Max_Heap(TYPE elementsArray[], int size, int capacity) {
    (capacity != 0)? this->capacity = capacity : this->capacity = size;
    this->size = size;
    this->contentHeap = new TYPE[this->capacity];
    for(int i=0; i < size; i++)
        this->contentHeap[i] = elementsArray[i];
    arrange();
}

/**
 * 
 */
template<class TYPE>
inline int Max_Heap<TYPE>::getFather(int position) {
    return (position-1)/2;
}

template<class TYPE>
inline int Max_Heap<TYPE>::getLeftChild(int position) {
    return (2 * position + 1);
}

template<class TYPE>
inline int Max_Heap<TYPE>::getRightChild(int position) {
    return (2 * position + 2);
}

template<class TYPE>
void Max_Heap<TYPE>::arrange() {
    for(int i = (size/2)-1; i>=0; i++) //errei aqui
        arrangeUp(i);
}

template<class TYPE>
void Max_Heap<TYPE>::arrangeUp(int position) {
    int fatherPosition = getFather(position);
    if(this->contentHeap[fatherPosition] < this->contentHeap[position]) {
        swap(contentHeap[fatherPosition], this->contentHeap[position]);
        arrangeUp(fatherPosition);
    }
}

template<class TYPE>
void Max_Heap<TYPE>::arrangeDown(int position) {
    int leftChildPosition = getLeftChild(position);
    int rightChildPosition = getRightChild(position);
    int higher;

    (this->contentHeap[leftChildPosition] > this->contentHeap[position])? higher = leftChildPosition : higher = position;

    (this->contentHeap[rightChildPosition] > this->contentHeap[position])? higher = rightChildPosition : higher = position;

    if(position != higher) {
        swap(this->contentHeap[position], this->contentHeap[higher]);
        arrangeDown(higher);
    }
}

template<class TYPE>
inline TYPE Max_Heap<TYPE>::getRoot() {
    return this->contentHeap[0];
}

template<class TYPE>
void Max_Heap<TYPE>::insert(TYPE data) {
    if(this->size < this->capacity) {
        this->contentHeap[this->size] = data;
        this->size++;
    }else {
        exit(EXIT_FAILURE);
    }
}

template<class TYPE>
TYPE Max_Heap<TYPE>::print() {
    TYPE heap;

    for(int i=0; i<this->size; i++) {
        heap += this->contentHeap[i];
    }
    return heap;
}