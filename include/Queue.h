/**
 * \file Queue.h
 *
 * This header file contains the Queue data structure 
 * method prototypes and her class declaration.
 *
 * \date Create: 21/06/2017
 * \date Alteration: 21/06/2017
 * \author Lucas Fonseca dos Santos
 */
#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H 1
#include <string>
#define SUCCESSFUL_MSG "Operation Successful!"
#define EMPTY_QUEUE_MSG -99999

using namespace std;

/**
 * Type to be used for queue content.
 *
 * \typedef Data
 */
typedef int Data;

/**
 * Class that describes the node object,
 * element of queue data structure.
 */
class Node {

   friend class Queue;

   private:

      /**
       * Content type of the queue.
       *
       * \var content
       * \remark Can be replaced by the type worked.
       */
      Data content;

       /**
        * Node pointer to the next node or element in queue.
        * This queue structure was implemented by linked form.
        *
        * \var next
        */
      Node* next;
   
   public:

      /**
       * Node element object constructureor.
       *
       * \param d Type of node content.
       * \remark If the user doesn't pass the parameter, him receives 0 value.
       */
      Node(Data d=0);

      /**
       * Node element object destructureor.
       */
      ~Node();

};

/**
 * Class that describes the Queue data linked structure.
 */
class Queue {
   
   private:

      /**
       * Node pointer to the first element of queue.
       *
       * \remark Only it can be used by the user to remove the elements of queue.
       * \var firstElement
       */
      Node* firstElement;

      /**
       * Node pointer to the last element of queue.
       *
       * \remark Only it can be used by the user to insert a new elements on queue.
       * \var lastElement
       */
      Node* lastElement;

      /**
       * Integer queue size attribute.
       *
       * \var size
       */
      int size;
   
   public:

      /**
       * Queue data structure construtor.
       */
      Queue();

      /**
       * Queue data structure destructureor.
       */
      ~Queue();

      /**
       * This method is responsible for new elements insertion or enqueue this case. By the queue data structure protocol, the new element always
       * will be inserted at the end of queue.
       *
       * \param content New element to be enqueued at queue.
       * \return string Successful or failure message about the operation.
       */
      string enqueue(Data content);

      /**
       * This method is reponsible for the removal queue elements. He
       * manipulates the last queue element and remove it, following the
       * queue data structure protocol. FIFO - First in, first out.
       *
       * \return Data Element dequeued.
       */
      Data dequeue();

      /**
       * This method returns the size state of queue structure.
       *
       * \return int Integer size queue.
       */
      int getSize();

      /**
       * This method verifys if the queue is empty. If yes, this method returns
       * true. He verifys if the first queue element is NULL.
       *
       * \return bool Returns if the queue is empty.
       */
      inline bool isEmpty();

      /**
       * This method is responsible to print out all queue elements formatted
       * on string.
       *
       * \return string String with all queue elements formmated.
       */
      string print();

};

#endif