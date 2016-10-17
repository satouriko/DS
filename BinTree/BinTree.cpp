#include "BinTree.h"
#include "../Stack/stack.h"
#include "../Queue/queue.h"

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

template <typename T>
vector<BinNode<T>*> BinTree<T>::preTraverse()
{
    vector<BinNode<T>*> ret;
    stack<BinNode<T>*> stk;
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

template <typename T>
vector<BinNode<T>*> BinTree<T>::inTraverse()
{
    vector<BinNode<T>*> ret;
    stack<BinNode<T>*> stk;
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

template <typename T>
vector<BinNode<T>*> BinTree<T>::levTraverse()
{
    vector<BinNode<T>*> ret;
    queue<BinNode<T>*> que;
    que.push(root);
    while(que.size() != 0) {
        BinNode<T>* temp = que.dequeue();
        ret.push(temp);
        if(temp.LChild != 0)
            que.enqueue(temp.LChild);
        if(temp.RChild != 0)
            que.enqueue(temp.RChild);
    }
    return ret;
}
