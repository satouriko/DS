//
// Created by lijiahao on 9/17/16.
//

#include "list.h"

template <typename T>
list<T>::list()
{
    header = new node<T>;
    trailer = new node<T>;
    header->succ = trailer;
    trailer->pred = header;
    header->pred = 0;
    trailer->succ = 0;
}

template <typename T>
list<T>::list(T *begin, T *end)
{
    header = new node<T>;
    trailer = new node<T>;
    header->succ = trailer;
    trailer->pred = header;
    header->pred = 0;
    trailer->succ = 0;
    for (T *p = begin; p != end; ++p)
        push(*p);
}

template <typename T>
const T &list<T>::get(size_t r) const
{
    node<T> *n = header;
    for (size_t i = 0; i < r + 1; ++i) {
        n = n->succ;
    }
    return n->data;
}

template <typename T>
void list<T>::push(T e)
{
    node<T> *p = new node<T>(e);
    p->pred = trailer->pred;
    p->pred->succ = p;
    p->succ = trailer;
    trailer->pred = p;
}

template <typename T>
const T &list<T>::put(size_t r, T e)
{
    node<T> *n = header;
    for (size_t i = 0; i < r + 1; ++i) {
        n = n->succ;
    }
    n->data = e;
    return n->data;
}

template <typename T>
size_t list<T>::insert(size_t r, T e)
{
    node<T> *n = header;
    for (size_t i = 0; i < r + 1; ++i) {
        n = n->succ;
    }
    node<T> *p = new node<T>(e);
    p->pred = n->pred;
    p->pred->succ = p;
    p->succ = n;
    n->pred = p;
    return r;
}

template <typename T>
size_t list<T>::destroy(node<T> *lo, node<T> *hi)
{
    hi->pred = lo->pred;
    lo->pred->succ = hi;
    size_t cnt = 0;
    for (node<T> *p = lo; p != hi;) {
        node<T> *tmp = p;
        p = p->succ;
        //p->~node();
        delete tmp;
        ++cnt;
    }
    return cnt;
}

template <typename T>
size_t list<T>::destroy(node<T> *x)
{
    return destroy(x, x->succ);
}

