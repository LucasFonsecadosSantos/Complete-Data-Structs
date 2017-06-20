/**
 * \file Stack.h
 *
 * This file contains the types and structs used by
 * the Stack data struct.
 *
 * \date Creation: 20/06/2017
 * \date Alteration: 20/06/2017
 * \author Lucas Fonseca dos Santos
 */
#ifndef STACK_TYPE_H
#define STACK_TYPE_H 1
#define SUCCESS_MSG "Successful Operation!"
#define FAILURE_ELEMENT -99999

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
 * element of the stack data struct.
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
       * This stack struct was implemented by linked form.
       *
       * \var next
       */
      Node* next;

   public:

      /**
       * Constructor of node element object.
       * 
       * \param d Type of node content.
       * \remark If the user doesn't pass the param, him receives 0 value.
       */
      Node(Data d=0);

      /**
       * Destructor of node element object.
       */
      ~Node();

};


/**
 * Class that describes the Stack data struct.
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
       * Stack data struct object constructor.
       */
      Stack();

      /**
       * Stack data struct object destructor.
       */
      ~Stack();

      /**
       * Push prototype method by stack to 
       * insert new data elements in struct.
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
       * remove an element in struct. This method,
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

};

#endif