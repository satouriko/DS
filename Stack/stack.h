#ifndef DS_STACK_H
#define DS_STACK_H

#include "../Vector/Vector.h"

template <typename T> class stack: public vector<T>
{
public:
    //void push(const T &e);
    T pop();
    T top();
};

#include "stack.cpp"

#endif
