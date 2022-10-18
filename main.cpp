#include <iostream>
#include "AVL.h"
using namespace std;

/* 
TASKS:

-make compare function and make a function pointer as a parameter of AVLtree constructor
-insert deletion;

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
    int(*compare)(int , int)=compareNode; //function pointer to compareNode named *scompare
    AVLtree<int> tree(compare);
    tree.insert(2);
    tree.insert(392);
    tree.insert(239);
    tree.insert(32);
    tree.insert(57009);
    return 0;
}

//need to put in second parameter into insert -> eg. insert(root, 3209)