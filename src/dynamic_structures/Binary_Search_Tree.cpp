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
        Node* currentNode = this->root;
        while(currentNode != NULL) {
            if(content == currentNode->content) {
                return currentNode;
            }else if(content > currentNode->content) {
                currentNode = currentNode->right;
            }else {
                currentNode = currentNode->left;
            }
        }
        return currentNode;
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

inline bool BinarySearchTree::isLeaf(Node* node) {
    return ((node->left == NULL) && (node->right == NULL));
}

std::string BinarySearchTree::remove(Data content) {

    Node* targetNode = search(content);
    if(targetNode != NULL) {
        if(targetNode->right == NULL){
            swaper(targetNode, targetNode->left);
        }else if(targetNode->left == NULL) {
            swaper(targetNode, targetNode->right);
        }else {

            Node* successor = minimum(targetNode->right);

            if(isLeaf(successor)) {
                successor = maximum(targetNode->left);
            }

            if(successor->father != targetNode) {
                swaper(successor, successor->right);
                successor->right = targetNode->right;
                successor->right->father = successor;
            }
            swaper(targetNode, successor);
            successor->left = targetNode->left;
            successor->left->father = successor;
        }
        targetNode->left = NULL;
        targetNode->right = NULL;
        delete targetNode;
        return "REMOVED";
    }else {
        return "ELEMENT NOT FOUND";
    }

}

Node* BinarySearchTree::maximum(Node* currentNode) {
    while(currentNode->right != NULL) {
        currentNode = currentNode->right;
    }
    return currentNode;
}

Node* BinarySearchTree::minimum(Node* tmpNode) {
    while(tmpNode->left != NULL) {
        tmpNode = tmpNode->left;
    }
    return tmpNode;
}

std::string BinarySearchTree::inOrderPrinter() {
    return inOrderPrinter(this->root, 0);

}

std::string BinarySearchTree::inOrderPrinter(Node* currentNode, int level) {
    std::string s;
    if(currentNode != NULL) {
        inOrderPrinter(currentNode->left, level+1);
        s += currentNode->content;
        std::cout << currentNode->content << " ";
        inOrderPrinter(currentNode->right, level+1);
    }
    return s;
}

std::string BinarySearchTree::postOrderPrinter() {
    return postOrderPrinter(this->root);
}

std::string BinarySearchTree::postOrderPrinter(Node* currentNode) {
    std::string s;
    if(currentNode != NULL) {
        postOrderPrinter(currentNode->left);
        postOrderPrinter(currentNode->right);
        s += currentNode->content;
        std::cout << currentNode->content << " ";
    }
    return s;
}

std::string BinarySearchTree::preOrderPrinter() {
    return preOrderPrinter(this->root);
}

std::string BinarySearchTree::preOrderPrinter(Node* currentNode) {
    std::string s;
    if(currentNode != NULL) {
        s += currentNode->content;
        std::cout << currentNode->content << " ";
        preOrderPrinter(currentNode->left);
        preOrderPrinter(currentNode->right);
    }
    return s;
}

int main() {
    BinarySearchTree* bt = new BinarySearchTree();
    std::cout << bt->add(35);
    std::cout << std::endl;
    std::cout << bt->add(14);
    std::cout << std::endl;
    std::cout << bt->add(45);
    std::cout << std::endl;
    std::cout << bt->add(6);
    std::cout << std::endl;
    std::cout << bt->add(23);
    std::cout << std::endl;
    std::cout << bt->add(39);
    std::cout << std::endl;
    std::cout << bt->add(57);
    std::cout << std::endl;
    std::cout << bt->add(1);
    std::cout << std::endl;
    std::cout << bt->add(8);
    std::cout << std::endl;
    std::cout << bt->add(21);
    std::cout << std::endl;
    std::cout << bt->add(28);
    std::cout << std::endl;
    std::cout << bt->add(36);
    std::cout << std::endl;
    std::cout << bt->add(41);
    std::cout << std::endl;
    std::cout << bt->add(22);
    std::cout << std::endl;
    std::cout << bt->add(32);
    std::cout << bt->remove(14);
    bt->preOrderPrinter();
    std::cout << std::endl;
    bt->postOrderPrinter();
    std::cout << std::endl;
    bt->inOrderPrinter();
    return 0;
}