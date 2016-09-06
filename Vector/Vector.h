#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class vector {
	T* _elem;
	size_t _size;
	size_t _capacity;

	size_t full();

	public:

	vector();
	vector(T* begin, T* end);

	const size_t size() const;
	const T& get(size_t r) const;
	size_t push(T e);
	const T& put(size_t r, T e);
	size_t insert(size_t r, T e);
	unsigned disordered();
	void sort();
	size_t find(T e);
	size_t deduplicate();
	size_t uniquify();

	~vector();
};

#include "Vector.cpp"

#endif
