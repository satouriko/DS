#include "BinTree.h"
#include "../Stack/stack.h"

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

vector<BinNode<T>*> BinTree<T>::preTraverse()
{
    vector<BinNode<T>*> ret();
    stack<BinNode<T>*> stk();
    stk.push(root);
    while(stk.size() != 0)
    {
        BinNode<T> *temp = stk.pop();
        ret.push(temp);
        if(temp.RChild != 0)
            stk.push(temp.RChild);
        if(temp.LChild != 0)
            stk.push(temp.LChild);
    }
    return ret;
}

vector<BinNode<T>*> BinTree<T>::inTraverse()
{
    vector<BinNode<T>*> ret();
    stack<BinNode<T>*> stk();
    stk.push(root);
    while(stk.size() != 0)
    {
        BinNode<T> *temp = stk.top();
        if(temp.LChild != 0)
        {
            stk.push(temp.LChild);
        }
        else
        {
            stk.pop();
            ret.push(temp);
            if(temp.RChild != 0)
                stk.push(temp.RChild);
        }
    }
    return ret;
}
