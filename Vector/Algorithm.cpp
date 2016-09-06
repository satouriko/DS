using namespace std;

template <typename T>
int vector<T>::find(T e)
{
	T *p = _elem + _size - 1;
	for(; p >= _elem; --p)
	{
		if(*p == e)
			break;
	}
	return p - _elem;
}

template <typename T>
int vector<T>::find(size_t lo, size_t hi, T e)
{
	T *p = _elem + hi - 1;
	for(; p >= _elem + lo; --p)
	{
		if(*p == e)
			break;
	}
	return p - (_elem + lo);
}

template <typename T>
size_t vector<T>::deduplicate()
{
	size_t p = 0;
	size_t oldSize = _size;
	for(; p != _size; ++p)
	{
		if(find(0, p, get(p)) >= 0)
			destroy(p--);
	}
	return oldSize - _size;
}

