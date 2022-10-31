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
    AVLnode() { //defualt constructor
        this->data = NULL;
        right = left = nullptr;
        leftHeight = rightHeight = 0;
    }
    AVLnode(T data){ 
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
    void searchTest(T data){
        AVLnode<T>* found;
        found = search(root, data);
        if (found!=nullptr){
            cout << "THIS IS THE ITEM FOUND: " << found->getData() << endl;            
        }
    }
    AVLnode<T>* search(AVLnode<T> *root_ptr, T key){
        if (root_ptr==nullptr){ //if tree is empty OR node not found, exit function
            cout << key << " NOT FOUND!" << endl;
            return root_ptr;
        }
        else if (root_ptr->getData() == key){ //if node searched is root OR node is found, return
            cout << key << " FOUND!" << endl;
            return root_ptr;
        }
        else{
            if (key < root_ptr->getData()){ //if key is less than parent, search left tree
                return search(root_ptr->left, key); //keep searching left
            }
            else if (key > root_ptr->getData()){ //if key is more than parent, search right
                return search(root_ptr->right, key); //keep search right
            }
        }
        return nullptr; //if data not found return nullptrs;
    }
    void insertNode(T data){ //function only takes data as parameter so root is not accessed in main
        root=insertNodePrivate(root, data);
    }
    AVLnode<T>* insertNodePrivate(AVLnode<T> *root_ptr, T dataInsert){
        if (root_ptr==nullptr){ //base case (root empty) or encounter leaf node then insert
            root_ptr = new AVLnode<T>(dataInsert);
            count++; //increment node count by 1;
            return root_ptr;
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == 1){ //if data > parent, insert right
            root_ptr->right=insertNodePrivate(root_ptr->right, dataInsert); //recursive implementation
            //root_ptr=balance(root_ptr); //balance tree if unbalanced (right cases)
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == -1){ //if data < parent, insert left
            root_ptr->left=insertNodePrivate(root_ptr->left, dataInsert);
            //root_ptr=balance(root_ptr);
        }
        else if (comparePtr(dataInsert, root_ptr->getData()) == 0){ //if data is repeated, print out error
            cout << "CANNOT REPEAT DATA" << endl;
        }
        return balance(root_ptr); //balance if it is unbalanced
    }
    void deleteNode(T data){
        root=deleteNodePrivate(root, data);
    }
    AVLnode<T>* deleteNodePrivate(AVLnode<T> *root_ptr, T key){
        //FIRST: search for node to be deleted
        if (root_ptr==nullptr){ //if tree is empty or node is not found, return pointer
            return nullptr;
        }
        else if (comparePtr(key,root_ptr->getData()) == -1){ //if key is less than parent, node to delete is in left subtree
            root_ptr->left=deleteNodePrivate(root->left, key);
        }
        else if (comparePtr(key,root_ptr->getData()) == 1){ //if key is greater than parent, node to delete is in right subtree
            root_ptr->right=deleteNodePrivate(root->right, key);
        }
        else{ //if key = data, we are at the node to be deleted
            if (root_ptr->left == nullptr && root_ptr->right == nullptr) { //CASE 1: node with no children
                return nullptr;
            }
            else if (root_ptr->left == nullptr) { //CASE 2: right child only
                AVLnode<T>* tempNode = root_ptr->right; //right child becomes successor
                free(root_ptr); //delete node
                return tempNode;
            }
            else if (root_ptr->right == nullptr) { //CASE 3: left child only
                AVLnode<T>* tempNode = root_ptr->left; //left child becomes successor
                free(root_ptr); //delete node
                return tempNode;
            }
            //CASE 4: node with 2 children
            AVLnode<T>* tempNode = minValue(root_ptr->right); //get inorder successor (right, then left all the way down till null)
            root_ptr->setData(tempNode->getData()); //copy inorder successor value into node
            root_ptr->right = deleteNodePrivate(root_ptr->right, tempNode->getData()); //delete key
        }
        count--; //decrement cound by 1 when node is deleted;
        return balance(root_ptr); //balance before returning.
        //USING SEARCH FUNCTION WILL NOT WORK (cannot get access to parent node)
        // AVLnode<T>* tempRemove = root_ptr;
        // if (root_ptr=nullptr){ //if tree is empty, return pointer
        //     return root_ptr;
        // }
        // else{
        //     tempRemove = search(root_ptr, data); //look for node to be deleted and when found set to tempRemove 
        //     //delete by copy: copy child node, delete node, make child parent
        //     //4 cases:
        //     if (tempRemove->left==nullptr || tempRemove->right==nullptr){ //node to delete has one child, or no children
                
        //     }
        // }
    }
    AVLnode<T>* minValue(AVLnode<T>* tree) { //get mininum value of a bst
        while (tree->left != nullptr) {
            tree = tree->left;
        }
        return tree;
    }
    int calcBalanceFactor(AVLnode<T>* tree){
        int lHeight;
        int rHeight;
        lHeight=root->calcHeight(tree->left); //calculate right height, it will also update rightHeight in AVLnode
        rHeight=root->calcHeight(tree->right);
        return rHeight-lHeight; //right height - left height
    }
    bool checkBalance(AVLnode<T>* tree){
        if (calcBalanceFactor(tree)>=-1 && calcBalanceFactor(tree) <=1){ //if -1 <= balance factor <= 1, tree is balanced
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
        tempParent = parent->right; //right child becomes new parent
        parent->right = llRotate(tempParent); // right rotation on new parent
        //tempParent=parent->right->left; //right child becomes temp new parent used for right rotate
        //tempParent->right=parent->right; // right rotation on temp new parent
        //parent->right=tempParent; //parent right aqquires right rotated tempParent
        //tempParent->left = nullptr; //set temp parent left pointer to null, now right right case
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
        tempParent=parent->left; //temp new parent set to left child
        parent->left = rrRotate(tempParent); //left rotation on new parent
        //tempParent->left=parent->left->right; //right rotate around temp parent
        //tempParent->right=nullptr; //set temp parent right pointer to null, now left left case
        cout << "Performed right left rotation" << endl;
        return llRotate(parent); //return left left case (can use llRotate to right rotate)
    }
};