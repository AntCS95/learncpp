#pragma once

#include <cstdint>
#include <cmath>
#include <cassert>
#include <iostream>

class FixedPoint2
{
public:
	FixedPoint2(int integral, int decimal)
	{
		// case any of the given numbers is negative, we consider the FixedPoint2
		// number is negative. In this case, both integral and decimal parts
		// are negative.
		if (integral < 0 || decimal < 0)
		{
			m_integral = -std::abs(integral);
			m_decimal = -std::abs(decimal);
		}
		else
		{
			// we are sure the provided numbers are positive at this point
			m_integral = integral;
			m_decimal = decimal;
		}
		// manage overflowing decimal parts
		while (m_decimal <= -100 || m_decimal >= 100)
		{
			if (m_decimal <= -100)
			{
				m_integral -= 1;
				m_decimal += 100;
			}
			if (m_decimal >= 100)
			{
				m_integral += 1;
				m_decimal -= 100;
			}
		}
	}
	FixedPoint2(int i)
	{
		// when an int is provided, it is treated as the integral and decimal
		// parts together without the decimal separator. Therefore, our mission
		// is to separate both parts.
		int integral, decimal;
		integral = static_cast<int>(i/100);
		decimal = i - integral * 100;
		*this = { integral, decimal };
	}
	FixedPoint2(double d)
	{
		// we generate the equivalent int needed for the corresponding
		// constructor
		*this = static_cast<int>(std::round(d * 100));
	}
	friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& num)
	{
		out << static_cast<double>(num);
		return out;
	}
	friend std::istream& operator >> (std::istream& in, FixedPoint2& num)
	{
		double d;
		in >> d;
		num = d;
		return in;
	}
	explicit operator double() const
	{
		// as both integral and decimal parts are sharing the same sign,
		// we dont have to worry about the sign of the number, and summing both
		// parts is sufficient
		return (m_integral + static_cast<double>(m_decimal) / 100);
	}
	explicit operator int() const
	{
		return (m_integral * 100 + m_decimal);
	}
	FixedPoint2 operator+(const FixedPoint2& fp)
	{
		return static_cast<int>(*this) + static_cast<int>(fp);
	}
	bool operator==(const FixedPoint2& fp) const
	{
		return (m_integral == fp.m_integral && m_decimal == fp.m_decimal);
	}
	FixedPoint2 operator-()
	{
		return { -m_integral, -m_decimal };
	}
private:
	int16_t m_integral{ 0 };
	int8_t m_decimal{ 0 };	
};