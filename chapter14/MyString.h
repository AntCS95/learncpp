#pragma once

#include <string>
#include <iostream>

class MyString
{
private:
	std::string m_string{};
public:
	MyString() = default;
	MyString(const std::string& string): m_string{string} {}

	friend std::ostream& operator<< (std::ostream& out, const MyString& string)
	{
		out << string.m_string;
		return out;
	}

	std::string_view operator() (int start, int length)
	{
		std::string_view view{ m_string };
		return view.substr(start, length);
	}
};
