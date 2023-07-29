#pragma once

#include <cstdint>
#include <cmath>
#include <cassert>
#include <iostream>

class FixedPoint2
{
public:
	FixedPoint2(int integral, int decimal)
		//m_integral{static_cast<int16_t>(integral)},
		//m_decimal{static_cast<uint8_t>(decimal)},
	{
		assert(decimal < 100 && "Decimal part is not 2 sized");
		m_integral = std::abs(integral);
		m_decimal = std::abs(decimal);
		m_negative = integral < 0 || decimal < 0;
	}
	FixedPoint2(double d)
	{
		m_integral = static_cast<int>(d);
		m_decimal = std::abs(static_cast<int>((d - m_integral)*100));
	}
	friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& num)
	{
		out << (num.m_negative ? '-' : '\0') << num.m_integral << '.';
		if (num.m_decimal < 10) out << '0';
		out << static_cast<int>(num.m_decimal);
		return out;
	}
	explicit operator double()
	{
		return (m_integral + static_cast<double>(m_decimal) / 100) * 
			(m_negative ? -1 : 1);
	}
private:
	int16_t m_integral{ 0 };
	uint8_t m_decimal{ 0 };
	bool m_negative{ false };
	
};