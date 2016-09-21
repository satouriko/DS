#include <iostream>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l)
{
    os << '(';
    for (node<T> *p = l.header->succ; p != l.trailer; p = p->succ) {
        os << p->data;
        if (p != l.trailer->pred)
            os << ", ";
    }
    os << ")";
    return os;
}
