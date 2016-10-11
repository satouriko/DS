#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

#include "BinNode.h"

template <typename T>
class BinTree {
public:
    BinNode<T> *root;
    BinTree(BinNode<T> *rt);
};

#include "BinTree.cpp"

#endif // BINTREE_H_INCLUDED
