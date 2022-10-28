#include <iostream>
#include "AVL.h"
using namespace std;

/* 
TASKS:

DONE -make compare function and make a function pointer as a parameter of AVLtree constructor
DONE -INSERTING INTO ROOT NODE WRONG fix
-lr and rl rotations might be wrong
DONE -balance factor
DONE -inorder function
-search function 
DONE -balance function
DONE -balance after every insertion
-deleteNodePrivate function
DONE -checkBalance function
DONE -count function
-fix extra found
-driver program
*/

template<typename T>
int compareNode(T left, T right){
    if (left < right) //if left node < right node, return -1
        return -1;
    else if (left == right) //if left node = right node, return 0
        return 0;
    else if (left > right) //if left node > right node, return 1
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
    tree.inorder();
    tree.searchTest(32);
    tree.searchTest(757);
    tree.searchTest(57009);
    cout << "# of nodes: " << tree.getCount();
    return 0;
}

//need to put in second parameter into insert -> eg. insert(root, 3209)