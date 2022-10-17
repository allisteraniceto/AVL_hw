#pragma once
#include <iostream>
using namespace std;

//implement as templated class (can use multiple data types)
template <class T>
class AVLnode{
private:
    T data;
    AVLnode<T>* left; //pointer to left child
    AVLnode<T>* right; //pointer to right child
public:
    AVLnode(){ //default constructor
        data = T(); //template syntax
        right = null; //child pointers to null
        left = null;
    }
};

template <class T>
class AVLtree{
private:
    AVLnode<T>* root; //pointer to root
    int balanceFactor; //balance factor
public:
    AVLtree(){
        root=null;
        int=0;
    }
    AVLnode insert(AVLnode<T>root, T data){
        if (root==null){ //base case
            root->T;
        }
        if (data > root->T){ //if data > parent
            root->right=insert(root, data); //recursive implementation
        }
        else if (data < root->T){ //if data < parent
            root->left=insert(root, data);
        }
        return root; 
    }
    //4 cases
    AVLtree llRotate(){};
    AVLtree lrRotate(){};
    AVLtree rrRotate(){};
    AVLtree rlRotate(){};
};