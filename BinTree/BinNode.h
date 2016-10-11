#ifndef BINNODE_H_INCLUDED
#define BINNODE_H_INCLUDED

template <typename T>
class BinNode {
public:
    T data;
    BinNode<T> *parent;
    BinNode<T> *LChild;
    BinNode<T> *RChild;

    BinNode();
    BinNode(T e, BinNode<T> *par);
    BinNode(T e, BinNode<T> *par, BinNode<T> *lc, BinNode<T> *rc);
    BinNode<T>* newAsLChild(T e);
    BinNode<T>* newAsRChild(T e);
    BinNode<T>* insertAsLChild(BinNode<T> *bn);
    BinNode<T>* insertAsRChild(BinNode<T> *bn);

};

#include "BinNode.cpp"

#endif // BINNODE_H_INCLUDED
