#include "vector.hpp"

Vector::Vector(std::size_t n, const int& value)
{
	m_capacity = 0;
	m_size = 0;
	m_values = nullptr;

	for(std::size_t i = 0; i < n; i++)
		push_tail(value);
}

Vector::Vector(const Vector& vector)
{
	m_capacity = vector.m_capacity;
	m_size = vector.m_size;

	m_values = new int[m_capacity];
	std::memcpy(m_values, vector.m_values, m_size * sizeof(int));
}

Vector::~Vector()
{
	if(m_values != nullptr)
		delete m_values;
}

Vector& Vector::operator=(const Vector& vector)
{
	m_capacity = vector.m_capacity;
	m_size = vector.m_size;

	m_values = new int[m_capacity];
	std::memcpy(m_values, vector.m_values, m_size * sizeof(int));

	return *this;
}

void Vector::push_tail(const int& value)
{
	if(m_capacity == m_size) //full
		_expand();

	m_values[m_size++] = value;
}

void Vector::clean()
{
	delete m_values;
	
	m_values = nullptr;
	
	m_size = 0;
	m_capacity = 0;
}

void Vector::erase(std::size_t pos)
{
	for(std::size_t i = pos + 1; i < m_size; i++)
		m_values[i - 1] = m_values[i];

	m_size--;
}

void Vector::_expand()
{
	if(isEmpty())
	{
		m_values = new int[1];
		m_capacity = 1;
		return;
	}

	//copy data of m_values
	int* data = new int[m_size];
	std::memcpy(data, m_values, m_size * sizeof(int));

	//expand capacity of m_values
	m_capacity *= 2;
	delete m_values;
	m_values = new int[m_capacity];

	//restore old data to new m_values
	std::memcpy(m_values, data, m_size * sizeof(int));

	delete data;
}
