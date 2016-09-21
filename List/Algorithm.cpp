#include "node.h"
#include "list.h"

using namespace std;

template <typename T>
node<T> *list<T>::find(T e)
{
    return find(header, trailer, e);
}

template <typename T>
node<T> *list<T>::find(node<T> *lo, node<T> *hi, T e)
{
    node<T> *p = hi;
    while ((p = p->pred) != lo) {
        if (p->data == e)
            break;
    }
    return p;
}

template <typename T>
node<T> *list<T>::search(T e)
{
    return search(header, trailer, e);
}

template <typename T>
node<T> *list<T>::search(node<T> *lo, node<T> *hi, T e)
{
    node<T> *p = hi;
    while ((p = p->pred) != lo) {
        if (p->data <= e)
            break;
    }
    return p;
}

template <typename T>
size_t list<T>::deduplicate()
{
    node<T> *p = header->succ;
    while (p != trailer) {
        node<T> *tmp = find(header, p, p->data);
        if (tmp != header)
            destroy(tmp);
        p = p->succ;
    }
}

template <typename T>
void list<T>::swap(node<T> *lo, node<T> *hi)
{
    T tmp = lo->data;
    lo->data = hi->data;
    hi->data = tmp;
}

template <typename T>
void list<T>::selectionSort()
{
    for (node<T> *m = trailer; m != header; m = m->pred) {
        node<T> *p = header->succ;
        node<T> *max = header->succ;
        for (; p != m; p = p->succ) {
            if (p->data >= max->data)
                max = p;
        }
        if (m != header->succ && max != m->pred)
            swap(max, m->pred);
    }
}

template <typename T>
void list<T>::insertSort()
{
    for (node<T> *p = header->succ; p != trailer;) {
        node<T> *tmp = search(header, p, p->data);
        tmp->insertAsSucc(p->data);
        tmp = p;
        p = p->succ;
        destroy(tmp);
    }

}





