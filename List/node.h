//
// Created by lijiahao on 9/17/16.
//

#ifndef DSA_2016_NODE_H
#define DSA_2016_NODE_H

template <typename T>
class node {
    T data;
    node<T> *pred;
    node<T> *succ;
public:
    node();
    node(T e, p = 0, s = 0);
    node<T>* insertAsPred(const T &e);
    node<T>* insertAsSucc(const T &e);
};

#include "node.cpp"

#endif //DSA_2016_NODE_H
