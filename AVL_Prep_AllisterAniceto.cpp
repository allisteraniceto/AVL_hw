#include <iostream>
#include "AVL.h"
using namespace std;

template <typename T>
int compare(T left, T right){ //templated function used in parameter of avl constructor
    /*
    compare data points 
    if left < right, return -1
    else if left > right, return 1
    else if left == right, return 0
    */
    return 1; //return 1 
}

//driver function
int main(){
    /*
    make function pointer, pointing to compare function
    make an AVLtree object with function pointer as an argument 
    insert data into nodes here
    display tree after balancing
    */
    return 0;
}

#pragma once
#include <iostream>
using namespace std;

template<typename T> //templated node
class AVLnode{
public:
    /*
    pointer to left child
    pointer to right child
    int variable to keep track of left height
    int variable to keep track of right height
    */
private:
    AVLnode(T data){
        /*
        default constructor that takes in data for node
        */
    }
    int getHeight(){
        /*
        get height of right subtree and left subtree
        */
    }

};

template <typename T>
class AVLtree{
private:
    /*
    pointer to root node (AVLnode object)
    int variable for balance factor
    */
public:
    AVLtree(int (*compare_ptr)(T,T)){ //constructor has parameter that takes in function pointer
        /*
        root points to null
        balance factor set to 0
        */
    }
    void inorder(){
        /*
        inorder traversal to tree
        */
    }
    AVLnode<T>* insertNode(T data){
        /*
        insertNodePrivate here
        function takes in data only as parameter so root is not accessed in main
        */
    }
    AVLnode<T>* insertNodePrivate(AVLtree *root_ptr, T data){ //insert any data type as parameter
        /*
        if root is null, insert at root (base case)
        else if data > parent, insert to the right
        else if data < parent, insert to the left
        */
    }
    AVLnode<T>* deleteNode(T data){
        
    }
    
    AVLnode<T>* llRotate(){
        /*
        left-left case
        only one rotation needed
        rotate right around grandparent
        return new parent node
        */
    }
    AVLnode<T>* rrRotate(){
        /*
        symmetrical case right-right
        rotate left around grandparent
        return new parent node
        */
    }
    AVLnode<T>* lrRotate(){
        /*
        left-right case
        2 rotations needed
        rotate right then rotate left around grandparent (use llRotate)
        return llRotate with new parent node as parameter
        */
    }
    AVLnode<T>* rlRotate(){
        /*
        symmmetrical case right-left
        rotate left, then rotate right around grandparent (use rrRotate)
        return llRotate with ne parent node as parameter
        */
    }
    bool checkBalance(){
        /*
        checks balance factor at the node
        balance factor = right subtree - left subtree
        return true if balance, return false to indicate balancing is needed
        */
    }
};