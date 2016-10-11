#include "BinNode.h"

template <typename T>
BinNode<T>::BinNode() : data(0), parent(0), LChild(0), RChild(0) {}

template <typename T>
BinNode<T>::BinNode(T e, BinNode<T> *par) : data(e), parent(par), LChild(0), RChild(0) {}

template <typename T>
BinNode<T>::BinNode(T e, BinNode<T> *par, BinNode<T> *lc, BinNode<T> *rc) : data(e), parent(par), LChild(lc), RChild(rc) {}

template <typename T>
BinNode<T>* BinNode<T>::newAsLChild(T e)
{
    BinNode *bn = new BinNode(e, this);
    LChild = bn;
}

template <typename T>
BinNode<T>* BinNode<T>::newAsRChild(T e)
{
    BinNode *bn = new BinNode(e, this);
    RChild = bn;
}

template <typename T>
BinNode<T>* BinNode<T>::insertAsLChild(BinNode<T> *bn)
{
    bn->parent = this;
    LChild = bn;
}

template <typename T>
BinNode<T>* BinNode<T>::insertAsRChild(BinNode<T> *bn)
{
    bn->parent = this;
    RChild = bn;
}
