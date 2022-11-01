#include <iostream>
#include "AVL.h"
using namespace std;

/* 
TASKS:

DONE -make compare function and make a function pointer as a parameter of AVLtree constructor
DONE -INSERTING INTO ROOT NODE WRONG fix
DONE -lr and rl rotations might be wrong
DONE -balance factor
DONE -inorder function
DONE -search function 
DONE -balance function
DONE -balance after every insertion
DONE -deleteNodePrivate function
DONE -checkBalance function
DONE -count function
DONE -fix extra found
DONE -driver program
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
    tree.insertNode(5); 
    tree.insertNode(3);
    tree.insertNode(4);//right-left case
    tree.inorder();
    cout << "# of nodes: " << tree.getCount() << endl;
    tree.searchTest(392);
    tree.searchTest(757);
    tree.searchTest(4);
    tree.deleteNode(3); //CASE #1
    tree.deleteNode(4); //CASE #2
    tree.deleteNode(239); //CASE #4
    tree.deleteNode(392); //CASE #3
    tree.inorder();
    cout << "# of nodes: " << tree.getCount() << endl;
    return 0;
}

/*
Performed left left rotation
Performed left right rotation
Performed right right rotation
Performed right right rotation
Performed left left rotation
Performed right right rotation
Performed right left rotation
Performed left left rotation
1
2
3
4
5
32
34
239
392
# of nodes: 9
392 FOUND!
THIS IS THE ITEM FOUND: 392
757 NOT FOUND!
57009 NOT FOUND!
Performed right right rotation
Performed right left rotation
Performed left left rotation
1
2
3
4
5
34
# of nodes: 5

C:\Users\allister18\OneDrive - Columbia Basin College\Documents\CPTS223\AVLtreeDebugSol\Debug\AVLtreeDebug.exe (process 39440) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/