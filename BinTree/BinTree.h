#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

#include "BinNode.h"
#include "../Vector/Vector.h"

template <typename T>
class BinTree {
public:
    BinNode<T> *root;
    BinTree(BinNode<T> *rt);
    vector<BinNode<T>*> preTraverse();
    vector<BinNode<T>*> inTraverse();
    vector<BinNode<T>*> levTraverse();
};

#include "BinTree.cpp"

#endif // BINTREE_H_INCLUDED
