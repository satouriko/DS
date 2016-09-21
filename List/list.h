//
// Created by lijiahao on 9/17/16.
//

#ifndef DSA_2016_LIST_H
#define DSA_2016_LIST_H

#include <cstddef>

template <typename T>
class node;

template <typename T>
class list;

#include "cout.cpp"
#include "node.h"

template <typename T>
class list
{
    node<T> *header;
    node<T> *trailer;
public:
    list();
    list(T *begin, T *end);

    const size_t size() const;
    const T &get(size_t r) const;
    void push(T e);
    const T &put(size_t r, T e);
    size_t insert(size_t r, T e);
    size_t destroy(node<T> *lo, node<T> *hi);
    size_t destroy(node<T> *x);
    unsigned disordered();
    void sort();
    node<T> *find(T e);
    node<T> *find(node<T> *lo, node<T> *hi, T e);
    node<T> *search(node<T> *lo, node<T> *hi, T e);
    node<T> *search(T e);
    void swap(node<T> *lo, node<T> *hi);
    size_t deduplicate();
    void selectionSort();
    void insertSort();

    friend std::ostream &operator<< <T>(std::ostream &os, const list<T> &l);

};

#include "list.cpp"
#include "Algorithm.cpp"

#endif //DSA_2016_LIST_H
