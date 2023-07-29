#pragma once

#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray
{
public:
	IntArray(size_t size): m_size{size}, m_array{new int[size]} {}
	IntArray(const IntArray& array): IntArray(array.m_size)
	{
		for (size_t k{ 0 }; k < m_size; ++k)
		{
			m_array[k] = array.m_array[k];
		}
	}
	~IntArray() { delete[] m_array; }
	IntArray& operator=(const IntArray& array)
	{
		if (this == &array) return *this;
		m_size = array.m_size;
		delete[] m_array;
		m_array = new int[m_size];
		for (size_t k{ 0 }; k < m_size; ++k)
		{
			m_array[k] = array.m_array[k];
		}
		return *this;
	}
	int& operator[](size_t index) const
	{
		assert(index >= 0 && index < m_size && "index out of range");
		return m_array[index];
	}
	friend std::ostream& operator<<(std::ostream& out, IntArray& array)
	{
		for (size_t k{ 0 }; k < array.m_size; ++k)
		{
			out << array.m_array[k] << ' ';
		}
		return out;
	}
private:
	size_t m_size{};
	int* m_array{};

};
