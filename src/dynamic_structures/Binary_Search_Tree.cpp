#include "../../include/dynamic_structures/Binary_Search_Tree.h"
#include <string>
#include <iostream>
#include <cstddef>

/**
 * Binary search tree node object constructor.
 * He attributes null value to all pointer attributes.
 */
Node::Node(Data content) {
    this->father = NULL;
    this->left = NULL;
    this->right = NULL;
    this->content = content;
}

Node::~Node() {

}

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
    this->levelAmount = 0;
    this->nodeAmount = 0;
}

BinarySearchTree::~BinarySearchTree() {
    this->root = NULL;
    delete[] this;
}

inline bool BinarySearchTree::isEmpty() {
    return this->root == NULL;
}

std::string BinarySearchTree::add(Data content) {
    if(!isEmpty()) {
        
        Node* currentNode = this->root;
        Node* previusNode;
        direction addPosition;

        while(currentNode != NULL) {
            
            previusNode = currentNode;
            
            if(content > currentNode->content) {
                currentNode = currentNode->right;
                addPosition = right;
            }else if(content < currentNode->content) {
                currentNode = currentNode->left;
                addPosition = left;
            }
        }
        currentNode = new Node(content);
        currentNode->father = previusNode;
        (addPosition == left) ? previusNode->left = currentNode : previusNode->right = currentNode;
        this->nodeAmount++;
        return "SUCCESS";
    }else {
        this->root = new Node(content);
        this->levelAmount++;
        this->nodeAmount++;
        return "SUCCESS";
    }
}

Node* BinarySearchTree::search(Data content) {
    if(!isEmpty()) {
        if(this->root->content == content) {
            return this->root;
        }else {
            Node* currentNode = this->root;
            while(currentNode != NULL) {
                if(currentNode->content > content) {
                    currentNode = currentNode->left;
                }else if(currentNode->content < content) {
                    currentNode = currentNode->right;
                }
            }
            return currentNode;
        }
    }else {
        return NULL;
    }
}

void BinarySearchTree::swaper(Node* oldNode, Node* newNode) {
    if(this->root == oldNode) {
        this->root = newNode;
    }else if(oldNode == oldNode->father->left) {
        oldNode->father->left = newNode;
    }else if(oldNode == oldNode->father->right) {
        oldNode->father->right = newNode;
    }

    if(newNode != NULL) {
        newNode->father = oldNode->father;
    }
}

std::string BinarySearchTree::remove(Data content) {

    Node* targetNode = search(content);
    if(targetNode != NULL) {
        if(targetNode->right == NULL){
            swaper(targetNode, targetNode->left);
        }else if(targetNode->left == NULL) {
            swaper(targetNode, targetNode->right);
        }else {
            
        }
    }else {
        return "EMPTY TREE";
    }

}

int main() {
    BinarySearchTree* bt = new BinarySearchTree();
    std::cout << bt->add(56);
    std::cout << bt->add(23);

    return 0;
}