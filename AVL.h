#pragma once
#include <iostream>
#include <algorithm> //to get max function to compare left & right heights
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
    int calcHeight(AVLnode<T>* tree){
        int height=0; //initialize height variable
        if (tree != nullptr){ //while not a leaf node
            leftHeight=calcHeight(tree->left); //get height of left tree recursively
            rightHeight=calcHeight(tree->right);
            int maxHeight=max(leftHeight, rightHeight); //returns higher value
            height=maxHeight+1; //height algothrim
        }
        return height;
    }
    int getLeftHeight(){
        return leftHeight;
    }
    int getRightHeight(){
        return rightHeight;
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
        bool checkBalance=true;
    }
    void insertNode(T data){ //function only takes data as parameter so root is not accessed in main
        insertNodePrivate(root, data);
    }
    AVLnode<T>* insertNodePrivate(AVLnode<T> *root_ptr, T dataInsert){
        if (root_ptr==nullptr){ //base case or encounter leaf node then insert
            root_ptr = new AVLnode<T>(dataInsert);
            return root_ptr;
        }
        else if (compare(dataInsert, root_ptr->getData()) == 1){ //if data > parent
            root_ptr->right=insert(root_ptr, dataInsert); //recursive implementation
        }
        else if (compare(dataInsert, root->getData()) == -1){ //if data < parent
            root_ptr->left=insert(root_ptr, dataInsert);
        }
        else if (compare(dataInsert, root->getData()) == 0){
            cout << "CANNOT REPEAT DATA" << endl;
        }
        return root_ptr;
    }
    AVLnode<T>* balance(AVLnode<T>* tree){
        
    }
    //4 cases
    AVLnode<T>* llRotate(AVLnode<T>* parent){ //LEFT LEFT ROTATE (right rotate only)
        AVLnode<T> *newP; //new parent node
        newP=parent->left; //left child becomes parent
        parent->left=newP->right; //left child points to newP right child (null)
        newP->right=parent; //newp right child points to parent node
        cout << "Performed left left rotation" << endl;
        return newP; //return sub tree
    }
    AVLnode<T>* lrRotate(AVLnode<T>* parent){ //LEFT RIGHT ROTATE (right rotate, then rrRotate)
        AVLnode<T>* tempParent; //for first rotation
        tempParent=parent->right; //right child becomes temp new parent used for right rotate
        tempParent->right=parent->right->left; // right rotation on temp new parent
        tempParent->left=nullptr; //tempParent left child set to null, now in right right case;
        cout << "Performed left right rotation" << endl;
        return rrRotate(parent); //now left rotate around parent
    }
    AVLnode<T>* rrRotate(AVLnode<T>* parent){ //RIGHT RIGHT ROTATE (left rotate only)
        AVLnode<T> *newP; //new parent node
        newP=parent->right; //right child becomes parent
        parent->right=newP->left; //right child points to newP left (null)
        newP->left=parent;
        cout << "Performed right right rotation" << endl;
        return newP; 
    }
    AVLnode<T>* rlRotate(AVLnode<T>* parent){ //RIGHT LEFT ROTATE (left rotate, the llRotate)
        AVLnode<T>* tempParent;
        tempParent=parent->right; //temp new parent set to left child
        tempParent->left=parent->left->right; //right rotate around temp parent
        tempParent->right=nullptr; //set temp parent right pointer to null, now left left case
        cout << "Performed right left rotation";
        return llRotate(parent); //return left left case
    }
};