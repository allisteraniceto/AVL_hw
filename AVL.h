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
    AVLtree llRotate(AVLnode* parent){ //LEFT LEFT ROTATE (right rotate only)
        AVLnode *newP; //new parent
        newP=parent->left; //left child becomes parent
        parent->left=newP->right; //left child points to newP right child (null)
        newP->right=parent; //newp right child points to parent node
        cout << "Performed left left rotation" << endl;
        return newP; //return sub tree
    }
    AVLtree lrRotate(AVLnode* parent){ 
    }
    AVLtree rrRotate(AVLnode* parent){ //RIGHT RIGHT ROTATE (left rotate only)
        AVLnode *newP; //new parent
        newP=parent->right; //right child becomes parent
        parent->right=newP->left; //right child points to newP left (null)
        newP->left=parent;
        cout << "Performed right right rotation" << endl;
        return newP; 
    }
    AVLtree rlRotate(){};
};