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
    tree.insertNode(239); //left-right case
    tree.insertNode(32); 
    tree.insertNode(34);//right-right case
    tree.insertNode(1); //left-left case
    tree.insertNode(5); //right-left case
    tree.insertNode(57009);
    tree.inorder();
    cout << "# of nodes: " << tree.getCount() << endl;;
    tree.searchTest(392);
    tree.searchTest(757);
    tree.searchTest(57009);
    tree.deleteNode(392); //CASE #2
    tree.deleteNode(57009); //CASE #1
    tree.deleteNode(239); //CASE #3
    tree.deleteNode(32); //CASE #4
    tree.inorder();
    cout << "# of nodes: " << tree.getCount() << endl;
    return 0;
}

//need to put in second parameter into insert -> eg. insert(root, 3209)