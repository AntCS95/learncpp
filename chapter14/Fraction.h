#pragma once

#include <numeric>
#include <iostream>

class Fraction
{
public:
	Fraction() = default;
	Fraction(int num, int den=1): m_num{num}, m_den{den}
	{
		reduce();
	}

	void print() const
	{
		std::cout << m_num << '\\' << m_den << '\n';
	}

	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2)
	{
		return { frac1.m_num * frac2.m_num, frac1.m_den * frac2.m_den };
	}

	friend Fraction operator*(const Fraction& frac, int integer)
	{
		return { frac.m_num * integer, frac.m_den};
	}

	friend Fraction operator*(int integer, const Fraction& frac)
	{
		return frac * integer;
	}

private:
	int m_num{ 0 };
	int m_den{ 1 };

	void reduce()
	{
		int gcd{ std::gcd(m_num,m_den) };
		m_num /= gcd;
		m_den /= gcd;
	}

};