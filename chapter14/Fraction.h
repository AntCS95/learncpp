#pragma once

#include <numeric>
#include <iostream>
#include <string>

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
		std::cout << m_num << '/' << m_den << '\n';
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

	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac)
	{
		out << frac.m_num << '/' << frac.m_den;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Fraction& frac)
	{
		std::string text;
		in >> text;
		if (text.size() == 3 && text[1] == '/')
		{
			frac.m_num = text[0] - '0';
			frac.m_den = text[2] - '0';
			frac.reduce();
		}
		else
		{
			std::cout << "Invalid Input\n";
		}
		return in;
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