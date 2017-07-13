#ifndef BINARY_SEARCH_TREE_TYPE_H
#define BINARY_SEARCH_TREE_TYPE_H 1

#include <string>

typedef int Data;

enum direction {
    right,
    left
};

class Node {

    friend class BinarySearchTree;

    private:
        Node* left;
        Node* right;
        Node* father;
        Data content;
    
    public:
        Node(Data content);
        ~Node();
};

class BinarySearchTree {

    private:
        Node* root;
        int levelAmount;
        int nodeAmount;
        Node* search(Data);
        void swaper(Node*, Node*)
    
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        std::string add(Data);
        std::string remove(Data);
        inline bool isEmpty();
        std::string inOrderPrinter();
        std::string postOrderPrinter();
        std::string preOrderPrinter();
};

#endif