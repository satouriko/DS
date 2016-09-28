#ifndef DS_QUEUE_H
#define DS_QUEUE_H

template <typename T>
class queue;

#include "../List/list.h"

template <typename T> class queue: public list<T>
{
public:
    void enqueue(T const &e);
    T dequeue();
    T& front();
};

#include "queue.cpp"

#endif
