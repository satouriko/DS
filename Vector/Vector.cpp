#define DEFAULT_SIZE 32

using namespace std;

template <typename T>
vector<T>::vector() : _size(DEFAULT_SIZE), _capacity(DEFAULT_SIZE)
{
	_elem = new T(DEFAULT_SIZE);
}

template <typename T>
vector<T>::vector(T* begin, T* end) : _size(end - begin), _capacity(2 * (end - begin))
{
	_elem = new T(2 * (end - begin));
	for(T *p = _elem, *op = begin; op != end; ++op, ++p)
		*p = *op;
}

template <typename T>
size_t vector<T>::full()
{
	if(_size >= _capacity)
	{
		T *oldElem = _elem;
		_capacity = 2 * _size;
		_elem = new T(_capacity);
		for(T *op = oldElem, *np = _elem; op != oldElem + _size; ++op, ++np)
		{
			*np = *op;
		}
		delete oldElem;
	}
	return _capacity - _size;
}


template <typename T>
const size_t vector<T>::size() const
{
	return _size;
}

template <typename T>
const T& vector<T>::get(size_t r) const
{
	if(r >= _size)
		throw out_of_range("Out of range");
	else
		return _elem[r];
}

template <typename T>
size_t vector<T>::push(T e)
{
	full();
	_elem[_size++] = e;
	return _size;
}

template <typename T>
const T& vector<T>::put(size_t r, T e)
{
	if(r >= _size)
		throw out_of_range("Out of range");
	else
	{
		_elem[r] = e;
		return _elem[r];
	}
}

template <typename T>
size_t vector<T>::insert(size_t r, T e)
{
	full();
	T *p = _elem + _size + 1;
	for(; p != _elem + r;--p)
	{
		*p = *(p-1);
	}
	*p = e;
	++_size;
	return _size;
}

template <typename T>
vector<T>::~vector()
{
	delete _elem;
}

