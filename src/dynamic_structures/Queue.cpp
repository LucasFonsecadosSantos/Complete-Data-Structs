/**
 * \file Queue.cpp
 *
 * This file contains the implementation of Queue data structure.
 * 
 * \date Creation: 22/06/2017
 * \date Alteration: 22/06/2017
 * \author Lucas Fonseca dos Santos
 */
#include "../../include/Queue.h"
#include <string>

using namespace std;

/**
 * Queue object data structure constructor.
 */
Queue::Queue() {
    this->firstElement = NULL;
    this->lastElement = NULL;
    this->size = 0;
}

/**
 * Queue object data structure destructor.
 */
Queue::~Queue() {

}

/**
 * This method is responsible to insert or
 * enqueue new elements in queue structure. By the queue
 * data structure protocol, the new elements always will be
 * inserted at the end of queue.
 *
 * \param content New element to be enqueued at queue.
 * \return String Successful or failure message about the operation.
 */
string Queue::enqueue(Data content) {
    if(!isEmpty()) {
        this->lastElement->next = new Node(content);
        this->lastElement = this->lastElement->next;
        this->size++;
        return SUCCESSFUL_MSG;
    }else {
        this->firstElement = new Node(content);
        this->lastElement = this->firstElement;
        this->size++;
        return SUCCESSFUL_MSG;
    }
}

/**
 * This method returns if the queue is empty. If yes, it returns
 * true.
 *
 * \return bool Condition of the queue.
 */
inline bool Queue::isEmpty() {
    return (this->size == 0);
}

/**
 * This method is responsible to remove or dequeue queue elements.
 * He manipulates the last queue element and removes it, following
 * the queue data structure protocol. FIFO - First in, first out.
 *
 * \return Data Element dequeued.
 */
Data Queue::dequeue() {
    if(!isEmpty()) {
        Data element = this->firstElement->content;
        Node* tmpNode = this->firstElement;
        this->firstElement = this->firstElement->next;
        delete tmpNode;
        this->size--;
        return element;
    }else {
        return -99999;
    }
}

/**
 * This method returns the size attribute state.
 *
 * \return int Integer size attribute state.
 */
inline int Queue::getSize() {
    return (this->size);
}

/**
 * This method print out all the elments enqueued
 * on structure.
 *
 * \return string All elements enqueued.
 */
string Queue::print() {
    if(!isEmpty()) {
        string elements = "";
        Node* tmpNode = this->firstElement;
        while(tmpNode != NULL || tmpNode == this->lastElement) {
            elements += " | " + to_string(tmpNode->content);
            tmpNode = tmpNode->next;
        }

        return elements;
    }else {
        return "";
    }
}