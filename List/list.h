//
// Created by lijiahao on 9/17/16.
//

#ifndef DSA_2016_LIST_H
#define DSA_2016_LIST_H

#include "node.h"

template <typename T>
class list {
    size_t _size;
    node<T>* header;
    node<T>* trailer;
public:
    list();

    const size_t size() const;
    const T& get(size_t r) const;
    size_t push(T e);
    const T& put(size_t r, T e);
    size_t insert(size_t r, T e);
    size_t destroy(size_t lo, size_t hi);
    size_t destroy(size_t r);
    unsigned disordered();
    void sort();
    int find(T e);
    int find(size_t lo, size_t hi, T e);
    size_t search(T t, size_t m, size_t n);
    size_t search(T t);
    void swap(size_t i, size_t j);
    unsigned unsorted(size_t m, size_t n);
    unsigned unsorted();
    size_t deduplicate();
    size_t uniquify();
    void bubbleSortA1();
    void bubbleSortB1();
    void bubbleSortB2();

};

#include "list.cpp"

#endif //DSA_2016_LIST_H
