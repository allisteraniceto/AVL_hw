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
        data = T();
        right = 0;
        left = 0;
    }
};

template <class T>
class AVLtree{
private:
    AVLnode<T>* root; //pointer to root
    int balanceFactor; //balance factor
public:
    //4 cases
    AVLtree llRotate(){};
    AVLtree lrRotate(){};
    AVLtree rrRotate(){};
    AVLtree rlRotate(){};
};