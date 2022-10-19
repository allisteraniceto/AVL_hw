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
public:
    AVLnode(T data){ //default constructor
        this->data=data;
        right=left=nullptr; //child pointer to null
        leftHeight=rightHeight=0; //left and right height default zero
    }
    T getData(){
        return data;
    }
    int getLeftHeight(){
        return leftHeight;
    }
};

template <typename T>
class AVLtree{
private:
    AVLnode<T>* root; //pointer to root
    int balanceFactor; //balance factor
    bool checkBalance;
public:
    AVLtree(int(*compare)(T, T)){
        root=nullptr;
        int balanceFactor=0;
        bool checkBalance=NULL;
    }
    AVLnode insert(AVLnode<T> *root_ptr, T dataInsert){
        data=T;
        if (root==nullptr){ //base case
            root->T;
        }
        else if (compare(dataInsert,root->T.getData()) == 1){ //if data > parent
            root->right=insert(root, data); //recursive implementation
        }
        else if (compare(dataInsert, root->T.getData()) == -1){ //if data < parent
            root->left=insert(root, data);
        }
        else if (compare(dataInsert root->t.getData()) == 0){
            cout << "CANNOT REPEAT DATA" << endl;
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
        AVLnode<T>* tempParent; //for first rotation
        tempParent=parent->right; //right child becomes temp new parent used for right rotate
        tempParent->right=parent->right->left; // right rotation on temp new parent
        tempParent->left=nullptr; //tempParent left child set to null, now in right right case;
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
        tempParent->right=nullptr; //set temp parent right pointer to null, now left left case
        cout << "Performed right left rotation";
        return llRotate(parent); //return left left case
    }
};