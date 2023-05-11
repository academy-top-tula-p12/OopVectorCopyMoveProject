#include <iostream>
#include "Vector.h"

template<class T>
Vector<T>::~Vector()
{
	delete[] items;
}

//template <class T>
//Vector<T>::Vector(const Vector<T>& v) : size{ v.size }
//{
//	std::cout << "vector construct copy\n";
//	items = new T[size];
//	for (int i = 0; i < size; i++)
//		items[i] = v.items[i];
//}
//
//template<class T>
//Vector<T>& Vector<T>::operator=(const Vector& v)
//{
//	std::cout << "vector assign copy\n";
//	if (&v == this)
//		return *this;
//
//	delete[] items;
//	size = v.size;
//	items = new T[size];
//
//	for (int i = 0; i < size; i++)
//		items[i] = v.items[i];
//
//	return *this;
//}

template<class T>
Vector<T>::Vector(Vector&& v) noexcept
	: items{ v.items }, size{ v.size }
{
	std::cout << "vector construct move\n";
	v.size = 0;
	v.items = nullptr;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& v) noexcept
{
	std::cout << "vector assign move\n";
	if (&v == this)
		return *this;

	delete[] items;
	items = v.items;
	size = v.size;
	v.items = nullptr;
	v.size = 0;

	return *this;
}

template<class T>
int Vector<T>::Size() const
{
	return size;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return items[index];
}

template<class T>
const T& Vector<T>::operator[](int index) const
{
	return items[index];
}
