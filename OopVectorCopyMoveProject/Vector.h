#pragma once
template <class T>
class Vector
{
	int size;
	T* items;
public:
	Vector(int size)
		: size{ size }, items{ new T[size] } {}
	~Vector();

	Vector(const Vector<T>& v) = delete;
	Vector<T>& operator=(const Vector<T>& v) = delete;

	/*Vector(const Vector<T>& v);
	Vector<T>& operator=(const Vector<T>& v);*/

	Vector(Vector&& v) noexcept;
	Vector<T>& operator=(Vector&& v) noexcept;

	int Size() const;
	T& operator[](int index);
	const T& operator[](int index) const;
};

