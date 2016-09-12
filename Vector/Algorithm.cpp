using namespace std;

template<typename T>
int vector<T>::find(T e) {
    T *p = _elem + _size - 1;
    for (; p >= _elem; --p) {
        if (*p == e)
            break;
    }
    return p - _elem;
}

template<typename T>
int vector<T>::find(size_t lo, size_t hi, T e) {
    T *p = _elem + hi - 1;
    for (; p >= _elem + lo; --p) {
        if (*p == e)
            break;
    }
    return p - (_elem + lo);
}

template<typename T>
size_t vector<T>::deduplicate() {
    size_t p = 0;
    size_t oldSize = _size;
    for (; p != _size; ++p) {
        if (find(0, p, get(p)) >= 0)
            destroy(p--);
    }
    return oldSize - _size;
}

template<typename T>
void vector<T>::swap(size_t i, size_t j) {
    T temp = _elem[i];
    _elem[i] = _elem[j];
    _elem[j] = temp;
}

template<typename T>
unsigned vector<T>::unsorted(size_t m, size_t n) {
    unsigned ret = 0;
    for (T *p = _elem + m; p != _elem + n; ++p) {
        if (*p > *(p + 1))
            ++ret;
    }
    return ret;
}

template<typename T>
unsigned vector<T>::unsorted() {
    return unsorted(0, _size);
}

template<typename T>
void vector<T>::bubbleSortA1() {
    for (int i = _size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (_elem[j] > _elem[j + 1])
                swap(j, j + 1);
        }
    }
}

template<typename T>
void vector<T>::bubbleSortB1() {
    for (int i = _size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (_elem[j] > _elem[j + 1])
                swap(j, j + 1);
        }
        if (!unsorted(0, i))
            break;
    }
}

template<typename T>
size_t vector<T>::search(T t, size_t m, size_t n) {
    if (n - m <= 1)
        return m + 1;
    size_t mid = (m + n) / 2;
    if (_elem[mid] <= t)
        return search(t, mid, n);
    else
        return search(t, m, mid);
}

template<typename T>
size_t vector<T>::search(T t) {
    search(t, 0, _size);
}

template<typename T>
size_t vector<T>::uniquify() {
    T *p = _elem, *q = p;
    for (; p != _elem + _size; ++p) {
        if (*p != *q) {
            *(q + 1) = *p;
            ++q;
        }
    }
    size_t size = _size;
    _size = q - _elem + 1;
    return size;
}