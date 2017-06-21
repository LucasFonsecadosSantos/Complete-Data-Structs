/**
 * \file Stack.h
 *
 * This file contains the types and structures used by
 * the Stack data structure.
 *
 * \date Creation: 20/06/2017
 * \date Alteration: 20/06/2017
 * \author Lucas Fonseca dos Santos
 */
#ifndef STACK_TYPE_H
#define STACK_TYPE_H 1
#define SUCCESS_MSG "Successful Operation!"
#define FAILURE_ELEMENT -99999
#define STACK_EMPTY "This stack is empty!"

#include <string>

using namespace std;

/**
 * Type to be used for stack content.
 * 
 * \typedef Data
 */
typedef int Data;

/**
 * Class that describes the node object,
 * element of the stack data structure.
 */
class Node {
   
   friend class Stack;
   
   private:
      
      /**
       * Content type of the stack.
       *
       * \var content
       * \remark Can be replaced by the type worked. 
       */
      Data content;

      /**
       * Node pointer to the next node or element in stack.
       * This stack structure was implemented by linked form.
       *
       * \var next
       */
      Node* next;

   public:

      /**
       * Constructureor of node element object.
       * 
       * \param d Type of node content.
       * \remark If the user doesn't pass the param, him receives 0 value.
       */
      Node(Data d=0);

      /**
       * Destructureor of node element object.
       */
      ~Node();

};


/**
 * Class that describes the Stack data structure.
 */
class Stack {

   private:
      
      /**
       * Node pointer to the top of stack.
       *
       * \var top
       */
      Node* top;

      /**
       * The size value of stack.
       *
       * \var size
       */
      int size;
   
   public:

      /**
       * Stack data structure object constructureor.
       */
      Stack();

      /**
       * Stack data structure object destructureor.
       */
      ~Stack();

      /**
       * Push prototype method by stack to 
       * insert new data elements in structure.
       * This method always insert an element
       * on the top of the stack, following the
       * stack ptotocol.
       *
       * \param content New insertion data content.
       * \return String Result of operation: Success or failure.
       */
      string push(Data content);

      /**
       * Pop prototype method by stack to
       * remove an element in structure. This method,
       * always remove the top element, following the
       * protocol of the stack.
       *
       * \return Data Data element that was removed.
       */
      Data pop();

      /**
       * Empty prototype method, responsible to verifys
       * if the stack is empty. Returns true if the
       * stack condition is empty.
       *
       * \return bool Result of verify about the stack condition.
       */
      inline bool isEmpty();


      /**
       * Search prototype method by stack, responsible to search
       * an element passed by the user by the parameter. If the
       * element is found, returns true.
       *
       * \param d Data parameter to be found.
       * \return bool Result of element search.
       */
      bool searchElement(Data d);

      /**
       * getTop prototype method by stack is responsible to get
       * an element by stack top without remove him. It is looks
       * like a data spy method.
       *
       * \return Data Element spied in top.
       */
      inline Data getTop();

      /**
       * searchAndPopElement prototype method by stack is responsible
       * to search an especific element in stack struck and after that,
       * remove it. It uses an other auxiliar stack to execute this.
       */
      Data searchAndPopElement(Data d);

      /**
       * equals prototype method by stack is responsible to compare two
       * stacks and returns if them are equal.
       *
       * \param stackTwo Stack structure data to be comparated.
       * \return bool Result of comparation.
       */
      bool equals(Stack stackTwo);

      /**
       * This prototype method, getSize is responsible to returns the stack
       * stack size attribute state as integer.
       *
       * \return int Integer that represents the stack size.
       */
      inline int getSize();

      /**
       * print prototype method. This method is responsible to print N elements
       * presents in stack structure. It runs whole the stack and by a parameter passed
       * by the user of how many elements the user wants to print out.
       * This method doesn't remove the elements of stack.
       *
       * \return string String with all elements that the user wants to print out.
       * \param amount Integer- Amount of elements that the user wants to print out by stack.
       */
      string print(int amount);

      /**
       * print ptototype method. This method is responsible to print all the elements
       * presents in stack structure. It runs all the stack until it this empty. It's an
       * overload of print method, but it one has no parameters.
       *
       * \return string String with all the elements presents in the stack.
       */
      string print();
};

#endif