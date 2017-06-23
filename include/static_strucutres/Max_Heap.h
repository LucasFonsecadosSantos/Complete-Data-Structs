/**
 * \file Max_Heap.h
 *
 * This file contains the max heap header data structure.
 *
 * \date Creation: 22/07/2016
 * \date Alteration: 22/07/2016
 * \author Lucas Fonseca dos Santos
 */
#ifndef MAX_HEAP_TYPE_H
#define MAX_HEAP_TYPE_H 1

/**
 * Data type to be used as max heap content.
 *
 * \remark You can replace this type to other type to be used as max heap content.
 * \typedef Data
 */
typedef int Data;

/**
 * This class describes the max heap data structure object.
 */
class Max_Heap {

    private:
        
        /**
         * Data heap content attribute.
         *
         * \var contentHeap
         */
        Data* contentHeap;

        /**
         * Heap size attribute.
         * 
         * \var size
         */
        int size;
        
        /**
         * Heap data capacity attribute.
         *
         * \var capacity
         */
        int capacity;

        /**
         * 
         */
        inline int father(int i);

        /**
         * 
         */
        inline int right(int i);

        /**
         * 
         */
        inline int left(int i);

        /**
         * 
         */
        void arrange();

        /**
         * 
         */
        void arrangeDown(int i);

        /**
         * 
         */
        void arrangeUp(int i);

    public:

        /**
         * Max heap data structure object constructor with capactity declarated by user.
         * \param capacity Integer capacity value of heap.
         * \remark It is an overload constructor.
         */
        Max_Heap(int capacity);

        /**
         * Max heap data structure object constructor with capacity, data elements, and size declarated by the user. If the user doens't pass the capacity value, this state attribute will be set as 0.
         * If the user doens't pass the capacity value, this receives 0.
         *
         * \param elementsArray Data array with content elements of max heap.
         * \param size Integer size value of elements array.
         * \param capacity Integer capacity value of my heap structure.
         * \remark It is an overload constructor.
         */
        Max_Heap(Data elementsArray[], int size, int capacity=0);

        /**
         * Max heap data structure object destructor.
         */
        ~Max_Heap();
        
        /**
         * This method is responsible to print out all max heap structure elements.
         */
        void print();

        /**
         * This method returns the root element but not remove it.
         *
         * \return Data Data content root.
         */
        inline Data getRoot();

        /**
         * This method is responsible to remove the root element.
         *
         * \return Data Data content root removed.
         */
        Data removeRoot();

        /**
         * This method is responsible to inserting an elements into the heap.
         *
         * \param content Data content to be inserted.
         */
        void insert(Data content);
};

#endif