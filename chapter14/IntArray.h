#pragma once

#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray
{
public:
	IntArray(size_t size): m_size{size}, m_array{new int[size]} {}
	int& operator[](size_t index) const
	{
		assert(m_size > index && "index out of range");
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
