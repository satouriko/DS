#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

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
	size_t destroy(size_t lo, size_t hi);
	T destroy(size_t r);
	unsigned disordered();
	void sort();
	int find(T e);
	int find(size_t lo, size_t hi, T e);
	size_t deduplicate();
	size_t uniquify();

	~vector();
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &v);
	
#include "Vector.cpp"
#include "Algorithm.cpp"

#endif
