#pragma once

#include <cstdint>
#include <iostream>

class Average
{
private:
	std::int32_t m_sum{ 0 };
	std::int8_t m_count{ 0 };

public:
	Average() = default;
	Average& operator+=(int32_t integer)
	{
		m_sum += integer;
		++m_count;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Average& avr)
	{
		out << static_cast<double>(avr.m_sum) / avr.m_count;
		return out;
	}
};