#pragma once
#include <iostream>
using namespace std;

//implement as templated class (can use multiple data types)
template <typename T>
class AVLnode{
private:
    T data;
    AVLnode<T>* left; //pointer to left child
    AVLnode<T>* right; //pointer to right child
    int leftHeight;
    int rightHeight;
    bool checkBalance;
public:
    AVLnode(){ //default constructor
        data=null;
        right=null; //child pointer to null
        left=null;
    }
    AVLnode(typename T){ //overloaded constructor
        data = T;
        right = null; 
        left = null;
    }
    T getData(){
        return data;
    }
    int getHeight(){
        return;
    }
};

template <typename T>
class AVLtree{
private:
    AVLnode<T>* root; //pointer to root
    int balanceFactor; //balance factor
public:
    AVLtree(){
        root=null;
        int=0;
    }
    AVLnode insert(T data){
        if (root==null){ //base case
            root->T;
        }
        if (data > root->T.getData()){ //if data > parent
            root->right=insert(root, data); //recursive implementation
        }
        else if (data < root->T.getData()){ //if data < parent
            root->left=insert(root, data);
        }
        return root; 
    }
    //4 cases
    AVLtree llRotate(AVLnode<T>* parent){ //LEFT LEFT ROTATE (right rotate only)
        AVLnode<T> *newP; //new parent node
        newP=parent->left; //left child becomes parent
        parent->left=newP->right; //left child points to newP right child (null)
        newP->right=parent; //newp right child points to parent node
        cout << "Performed left left rotation" << endl;
        return newP; //return sub tree
    }
    AVLtree lrRotate(AVLnode<T>* parent){ //LEFT RIGHT ROTATE (right rotate, then rrRotate)
        AVLNode<T>* tempParent; //for first rotation
        tempParent=parent->right; //right child becomes temp new parent used for right rotate
        tempParent->right=parent->right->left; // right rotation on temp new parent
        tempParent->left=null; //tempParent left child set to null, now in right right case;
        cout << "Performed left right rotation" << endl;
        return rrRotate(parent); //now left rotate around parent
    }
    AVLtree rrRotate(AVLnode<T>* parent){ //RIGHT RIGHT ROTATE (left rotate only)
        AVLnode<T> *newP; //new parent node
        newP=parent->right; //right child becomes parent
        parent->right=newP->left; //right child points to newP left (null)
        newP->left=parent;
        cout << "Performed right right rotation" << endl;
        return newP; 
    }
    AVLtree rlRotate(AVLnode<T>* parent){ //RIGHT LEFT ROTATE (left rotate, the llRotate)
        AVLnode<T>* tempParent;
        tempParent=parent->right; //temp new parent set to left child
        tempParent->left=parent->left->right; //right rotate around temp parent
        tempParent->right=null; //set temp parent right pointer to null, now left left case
        cout << "Performed right left rotation";
        return llRotate(parent); //return left left case
    }
};