/**
 * \file Max_Heap.h
 *
 * This file contains a Max Heap data structure header.
 *
 * \date Creation: 23/06/2017
 * \date Alteration: 23/06/2017
 * \author Lucas Fonseca dos Santos
 */
#ifndef MAX_HEAP_TYPE_H
#define MAX_HEAP_TYPE_H 1

#include <string>

/**
 * Template class definition type.
 */
template<class TYPE>

/**
 * This class describes the Max heap data structure.
 */
class Max_Heap {

    private:

        /**
         * Data content max heap attribute.
         *
         * \remark TYPE is a generic type.
         * \var contentHeap Elements array of max heap content.
         */
        TYPE* contentHeap;

        /**
         * Integer max heap size attribute.
         *
         * \var size Integer max heap size.
         */
        int size;
        
        /**
         * Capacity or array lenght value attribute.
         *
         * \var capacity Integer max heap capacity value.
         */
        int capacity;

        /**
         * This method returns father element position on heap array.
         *
         * \param int Integer position value
         * \return int Father position value at heap array.
         */
        inline int getFather(int);
        
        /**
         * This method returns left child element position on heap array.
         *
         * \param int Integer position value
         * \return int Left child position value at heap array.
         */
        inline int getLeftChild(int);

        /**
         * This method returns right child element position on heap array.
         *
         * \param int Integer position value
         * \return int Right child position value at heap array.
         */
        inline int getRightChild(int);

        /**
         * This method arrange all elements on array by the max heap rules.
         */
        void arrange();

        /**
         * This method arrange all elements on heap array going down
         * the structure.
         *
         * \param int Integer position value
         */
        void arrangeDown(int);

        /**
         * This method arrange all elements on heap array going up
         * the structure.
         *
         * \param int Integer position value
         */
        void arrangeUp(int);



        
    public:

        /**
         * Max heap data structure object constructor.
         * It is an overload constructor, that receives by
         * parameter a heap capacity integer value.
         *
         * \param int Heap capacity integer value.
         */
        Max_Heap(int);

        Max_Heap(TYPE[], int, int);
        
        inline TYPE getRoot();

        TYPE print();

        void insert(TYPE);

};

 #endif