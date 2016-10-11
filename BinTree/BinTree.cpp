#include "BinTree.h"

template <typename T>
BinTree<T>::BinTree(BinNode<T> *rt) : root(rt) {}

// template <typename T>
// ostream &operator<<(ostream &os, const BinTree<T> &l)
// {
//     os << '(';
//     for (node<T> *p = l.header->succ; p != l.trailer; p = p->succ) {
//         os << p->data;
//         if (p != l.trailer->pred)
//             os << ", ";
//     }
//     os << ")";
//     return os;
// }
