template <typename T>
void queue<T>::enqueue(T const &e)
{
    return this->push(e);
}

template <typename T>
T queue<T>::dequeue()
{
    return this->destroy(this->header->succ);
}

template <typename T>
T& queue<T>::front()
{
    return this->header->succ->data;
}
