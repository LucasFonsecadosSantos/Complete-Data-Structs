/**
* \file Stack.cpp
*
* This file contains the Stack structure data object
* implementation.
*
* \data Creation: 20/06/2017
* \data Alteration: 20/06/2017
* \author Lucas Fonseca dos Santos
*/
#include "../include/Stack.h"

using namespace std;

/**
 * Node element object constructureor.
 *
 * \param d Node data content.
 */
Node::Node(Data d) {
   this->next = NULL;
   this->content = d;
}

/**
 * Node element object destructureor.
 */
Node::~Node() {
   this->next = NULL;
}

/**
 * Stack data structure object constructureor.
 */
Stack::Stack() {
   this->top = NULL;
   this->size = 0;
}

/**
 * Stack data structure object destructureor.
 */
Stack::~Stack() {
   if(isEmpty()) return;
   Node* tmpNode = this->top;
   Node* tmpPreviusNode;
   while(tmpNode->next != NULL)  {
      tmpPreviusNode = tmpNode;
      tmpNode = tmpNode->next;
      delete tmpPreviusNode;
   }
   delete this->top;
   this->top = NULL;
}

/**
 * Push method by stack to insert new data
 * elements in structure. This method always insert
 * an element on the stack top, following the stack protocol.
 *
 * \param content New insertion data content.
 * \return String Result of operation: Success or failure.
 */
string Stack::push(Data content) {
   if(!isEmpty()) {
      Node* tmpNode = new Node(content);
      tmpNode->next = this->top;
      this->top = tmpNode;
      this->size++;
      return SUCCESS_MSG;
   }else {
      this->top = new Node(content);
      this->size++;
      return SUCCESS_MSG;
   }
}

/**
 * Pop method by stack to remove an element 
 * in structure. This method, it always remove
 * the top element, following the protocol 
 * of the stack.
 *
 * \return Data Data element that was removed.
 */
Data Stack::pop() {
   if(isEmpty()) return FAILURE_ELEMENT;
   Data returnData = getTop();
   Node* tmpNode = this->top;
   this->top = this->top->next;
   delete tmpNode;
   this->size--;
   return returnData;
}

/**
 * This method verifys the condition of stack, if it is
 * empty or no. If it is empty, returns true.
 *
 * \return bool Result of verify about the stack condition.
 */
inline bool Stack::isEmpty() {
   return (this->top == NULL);
}

/**
 * This method gets top element of stack and returns it
 * without removes.
 *
 * \return Data Data element of stack top.
 */
inline Data Stack::getTop() {
   return this->top->content;
}

/**
 * This method searchs an element on stack structure and
 * returns if this element was found. THIS METHOD NOT
 * PRESERVES THE ELEMENTS.
 *
 * \return bool Boolean with result of element search.
 */
 bool Stack::searchElement(Data d) {
    if(!isEmpty()) {
      if(d == getTop()) return true;
      Stack* s = new Stack();
      bool search = false;
      while((pop() != d) && !isEmpty()) {
         (pop() == d)? search = !search : search;
         s->push(pop());
      }
      while(!s->isEmpty()) {
         push(s->pop());
      }
      return search;
    }else{
       return false;
    }
 }

 /**
  * This method is responsible to search an element in stack
  * struck and pop it. It uses an other auxiliar stack to execute
  * this.
  *
  * \param d Data element to search and pop.
  * \return Data Element poped by this method.
  */
Data Stack::searchAndPopElement(Data d) {
   if(!isEmpty()) {
      if(!(d == getTop())) {
        Stack* auxSt = new Stack();
        while(d != getTop() && !isEmpty()) {
           auxSt->push(pop());
        }
        Data result = FAILURE_ELEMENT;
        (d == getTop()) ? result  = getTop() : result;
        while(!auxSt->isEmpty()) {
           push(auxSt->pop());
        }
        return result;
      }else {
         return pop();
      }
   }else {
    return FAILURE_ELEMENT;
  }
}

/**
 * This method, returns the stack size attribute state
 * as integer.
 *
 * \return int Integer that represents the stack size.
 */
inline int Stack::getSize() {
  return this->size;
}

/**
 * This method compare if two stacks are equals.
 * It is considerated equals if in both stacks,
 * are founds the same elements.
 *
 * \param stackTwo Stack structure to be comparated.
 * \return bool Result of comparation.
 */
bool Stack::equals(Stack stackTwo) {
  if(getSize() != stackTwo.getSize()) return false;
  if(isEmpty() && stackTwo.isEmpty()) return true;

  Stack* auxStack1 = new Stack();
  Stack* auxStack2 = new Stack();
  
  while(pop() == stackTwo.pop()) {
    auxStack1->push(pop());
    auxStack2->push(pop());
  }
  if(isEmpty() && stackTwo.isEmpty()) {
    while(!auxStack1->isEmpty() && !auxStack2->isEmpty()) {
      push(auxStack1->pop());
      stackTwo.push(auxStack2->pop());
    }
    return true;
  }else {
    return false;
  }
}

/**
 * This method is responsible to print N elements presents
 * in the stack structure. The number N is a integer parameter
 * passed by the user to choose how many elements him wants
 * to print out.
 *
 * \return string String with all elements that the user wants to print out.
 * \param amount Integer- Amount of elements that the user wants to print out by stack.
 */
string Stack::print(int amount) {
  (amount > getSize()) ? amount = getSize() : amount;
  if(isEmpty()) return STACK_EMPTY;
  if(amount == 0) return "";
  if(amount == 1) return to_string(getTop());
  Node* tmpNode = this->top;
  
  Stack* auxStack = new Stack();
  string elements = "";
  Data content;

  while((amount > 0) || !isEmpty()) {
    content = pop();
    auxStack->push(content);
    elements += " " + to_string(content);
    amount--;
  }
  while(!auxStack->isEmpty()) {
    push(auxStack->pop());
  }
  return elements;
}