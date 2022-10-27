#pragma once
#include <iostream>
#include <algorithm> //to get max function to compare left & right heights
using namespace std;

//implement as templated class (can use multiple data types)
template <typename T>
class AVLnode{
private:
    T data; //data is only private member
public:
    AVLnode<T>* left; //pointer to left child
    AVLnode<T>* right; //pointer to right child
    int leftHeight;
    int rightHeight;
    AVLnode(T data){ //default constructor
        this->data=data;
        right=left=nullptr; //child pointer to null
        leftHeight=rightHeight=0; //left and right height default zero
    }
    T getData(){
        return data;
    }
    void setData(T data){
        this->data=data;
    }
    int calcHeight(AVLnode<T>* tree){
        int height=0; //initialize height variable
        if (tree != nullptr){ //while not a leaf node
            leftHeight=calcHeight(tree->left); //get height of left tree recursively
            rightHeight=calcHeight(tree->right);
            int maxHeight=max(leftHeight, rightHeight); //returns higher value
            height=maxHeight+1; //height algothrim, (+1 because it doesnt count the parent node)
        }
        return height;
    }
};

template <typename T>
class AVLtree{
private:
    AVLnode<T>* root; //pointer to root
    int balanceFactor; //balance factor
    //bool checkBalance;
    int (*comparePtr)(T left,T right);
    int count;
public:
    AVLtree(int(*comparePtr)(T, T)){
        this->root=nullptr;
        this->balanceFactor=0;
        //this->checkBalnce=true;
        this->comparePtr=comparePtr;
    }
    int getCount(){
        return count;
    }
    void inorder(){
        inorderPrivate(root);
    }
    void inorderPrivate(AVLnode<T>* root_ptr){
        if (root_ptr==nullptr){ //if ptr is null, exit function
            return;
        }
        inorderPrivate(root_ptr->left);
        cout << root_ptr->getData() << endl;
        inorderPrivate(root_ptr->right);
    }
    void insertNode(T data){ //function only takes data as parameter so root is not accessed in main
        root=insertNodePrivate(root, data);
    }
    AVLnode<T>* insertNodePrivate(AVLnode<T> *root_ptr, T dataInsert){
        if (root_ptr==nullptr){ //base case or encounter leaf node then insert
            root_ptr = new AVLnode<T>(dataInsert);
            return root_ptr;
            count++; //increment node count by 1;
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == 1){ //if data > parent, insert right
            root_ptr->right=insertNodePrivate(root_ptr->right, dataInsert); //recursive implementation
            root_ptr=balance(root_ptr); //balance tree if unbalanced (right cases)
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == -1){ //if data < parent, insert left
            root_ptr->left=insertNodePrivate(root_ptr->left, dataInsert);
            root_ptr=balance(root_ptr);
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == 0){
            cout << "CANNOT REPEAT DATA" << endl;
        }
        return root_ptr;
    }
    void deleteNode(T data){
        deleteNodePrivate(root, data);
    }
    AVLnode<T>* deleteNodePrivate(){

    }
    int calcBalanceFactor(AVLnode<T>* tree){
        int lHeight;
        int rHeight;
        lHeight=root->calcHeight(tree->left); //calculate right height, it will also update rightHeight in AVLnode
        rHeight=root->calcHeight(tree->right);
        return rHeight-lHeight; //right height - left height
    }
    bool checkBalance(AVLnode<T>* tree){
        if (calcBalanceFactor(tree)>=-1 || calcBalanceFactor(tree) <=1){ //if -1 <= balance factor <= 1, tree is balanced
            return true;
        }
        return false;
    }
    AVLnode<T>* balance(AVLnode<T>* tree){
        //balance is off when balance factor > 1 or < -1;
        //first check balance of tree.
        if (checkBalance(tree)){ //if tree is already balanced return tree
            return tree;
        }
        else{
            if (calcBalanceFactor(tree)<(-1)){ //if balance factor < -1, then balancing needed on left side
                if (calcBalanceFactor(tree->left)==-1){ //if balance factor of left child is -1, left-left rototate
                    tree=llRotate(tree);
                }
                else{   //if balance factor of left child is -1, right-left rotate;
                    tree=rlRotate(tree);
                }
            }
            if (calcBalanceFactor(tree)>1){ //if balance factor > 1, then balancing needed on right side
                if (calcBalanceFactor(tree->right)==1){ //if balance factor of right child is 1, right-right rotate
                    tree=rrRotate(tree);
                }
                else{
                    tree=lrRotate(tree); //if BF of right child = -1, left-right rotate
                }
            } 
        }
        return tree;
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