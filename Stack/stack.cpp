template <typename T>
T stack<T>::pop()
{
    return this->destroy(this->size()-1,this->size());
}

template <typename T>
T stack<T>::top()
{
    return (*this)[this->size() - 1];
}
