#include <iostream>
#include "AVL.h"
using namespace std;

/* 
TASKS:

DONE -make compare function and make a function pointer as a parameter of AVLtree constructor
DONE -INSERTING INTO ROOT NODE WRONG fix
-lr and rl rotations might be wrong
DONE -balance factor
-balance function
-insert deletion
-balance after every insertion

*/

template<typename T>
int compareNode(T left, T right){
    if (left < right)
        return -1;
    else if (left == right)
        return 0;
    else if (left > right)
        return 1;
}

int main(){
    int(*comparePtr)(int, int)=compareNode; //function pointer to compareNode named *scompare
    AVLtree<int> tree(comparePtr);
    tree.insertNode(2);
    tree.insertNode(392);
    tree.insertNode(239);
    tree.insertNode(32);
    tree.insertNode(57009);
    system("pause");
    return 0;
}

//need to put in second parameter into insert -> eg. insert(root, 3209)