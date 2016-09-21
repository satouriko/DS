//
// Created by lijiahao on 9/17/16.
//

#include "node.h"

template <typename T>
node<T>::node() : pred(0), succ(0) {}

template <typename T>
node<T>::node(T e, node<T> *p, node<T> *s) : data(e), pred(p), succ(s) {}

template <typename T>
node<T> *node<T>::insertAsPred(const T &e)
{
    node *n = new node(e);
    pred->succ = n;
    n->pred = pred;
    n->succ = this;
    pred = n;
    return n;
}

template <typename T>
node<T> *node<T>::insertAsSucc(const T &e)
{
    node *n = new node(e);
    succ->pred = n;
    n->succ = succ;
    n->pred = this;
    succ = n;
    return n;
}
