//
// Created by lijiahao on 9/17/16.
//

template <typename T>
node<T>::node() : pred(0), succ(0) {}

template <typename T>
node<T>::node(T e, p = 0, s = 0) : data(e), pred(p), succ(s) {}
