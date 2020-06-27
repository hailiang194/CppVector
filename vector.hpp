#ifndef VECTOR_HPP
	#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <cstring>

class Vector
{
public:
	//initialize vector with n elements and their value is value
	Vector(std::size_t n = 0, const int& value = 0);
    Vector(const Vector& vector);
	~Vector();
	Vector& operator=(const Vector& vector);

	//get the quantity of elements in Vector
	const std::size_t size() const;

	//get the capacity of Vector
	const std::size_t capacity() const;

	//check if Vector is empty
	const bool isEmpty() const;

	//access the first element of Vector when it is const
	const int& head() const;

	//access the first element of Vector
	int& head();

	//access the last element of Vector when it is const
	const int& tail() const;

	//aceess the last element of Vector
	int& tail();

	//access specified element with bounds checking when is is const
	const int& at(std::size_t pos) const;

	//access specified element with bounds checking
	int& at(std::size_t pos);

	//access specified element without bounds checking when is is const
	const int& operator[](std::size_t pos) const;

	//access specified element without bounds checking
	int& operator[](std::size_t pos);

	//add new element to the end of Vector
	void push_tail(const int& value);

	//clean all elements in Vector
	void clean();

	//remove specified element in Vector by its position
	void erase(std::size_t pos);

protected:
	int* m_values;
	std::size_t m_size; 
	std::size_t m_capacity;

	//expand double the capacity of Vector when push new element to full list
	void _expand();
};

inline const std::size_t Vector::size() const
{
	return m_size;
}

inline const std::size_t Vector::capacity() const
{
	return m_capacity;
}

inline const bool Vector::isEmpty() const
{
	return (m_size == 0);
}

inline const int& Vector::head() const
{
	return m_values[0]; 
}

inline int& Vector::head()
{
	return const_cast<int&>(static_cast<const Vector&>(*this).head());
}

inline const int& Vector::tail() const
{
	if(m_size <= 1)
		return m_values[0];

	return m_values[m_size - 1];
}

inline int& Vector::tail()
{
	return const_cast<int&>(static_cast<const Vector&>(*this).tail());
}

inline const int& Vector::at(std::size_t pos) const
{
	if(pos >= m_size)
		throw std::out_of_range("Out of range");

	return m_values[pos];
}

inline int& Vector::at(std::size_t pos)
{
	return const_cast<int&>(static_cast<const Vector&>(*this).at(pos));
}

inline const int& Vector::operator[](std::size_t pos) const
{
	return m_values[pos];
}

inline int& Vector::operator[](std::size_t pos)
{
	return const_cast<int&>(static_cast<const Vector&>(*this)[pos]);
}

#endif //VECTOR_HPP
