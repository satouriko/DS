//
// Created by lijiahao on 9/17/16.
//

template <typename T>
list<T>::list()
{
    header = new node<T>;
    trailer = new node<T>;
    header->succ = trailer;
    trailer->pred = header;
    header->pred = 0;
    trailer->succ = 0;
    _size = 0;
}

template <typename T>
const size_t list<T>::size() const
{
    return _size;
}

template <typename T>
const T& list<T>::get(size_t r) const
{
    node<T> *n = header;
    for(size_t i = 0; i < r + 1; ++i)
    {
        n = n->succ;
    }
    return n->data;
}

template <typename T>
size_t list<T>::push(T e)
{
    node<T> *p = new node(e);
    p->pred = trailer->pred;
    p->succ = trailer;
    trailer->pred = p;
    ++_size;
    return _size;
}

template <typename T>
const T& list<T>::put(size_t r, T e)
{
    node<T> *n = header;
    for(size_t i = 0; i < r + 1; ++i)
    {
        n = n->succ;
    }
    n->data = e;
    return n->data;
}

template <typename T>
size_t list<T>::insert(size_t r, T e)
{
    node<T> *n = header;
    for(size_t i = 0; i < r + 1; ++i)
    {
        n = n->succ;
    }
    node<T> *p = new node(e);
    p->pred = n->pred;
    p->succ = n;
    n->pred = p;
    return r;
}

template <typename T>
size_t list<T>::destroy(size_t lo, size_t hi)
{
    node<T> *n1 = header;
    node<T> *n2 = header;
    for(size_t i = 0; i < hi + 1; ++i)
    {
        if(i < lo + 1) {
            n1 = n1->succ;
        }
        n2 = n2->succ;
    }
    n2->pred = n1->pred;
    n1->pred->succ = n2;
    for(size_t i = 0; i < hi - lo; ++i)
    {
        n2 = n1->succ;
        n1->~node();
        n1 = n2;
    }
    return lo - hi;
}

template <typename T>
size_t destroy(size_t r)
{
    return destroy(r, r+1);
}

