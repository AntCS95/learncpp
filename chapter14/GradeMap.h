#pragma once

#include "StudentGrade.h"

#include <vector>
#include <algorithm>

class GradeMap
{
public:
	char& operator[](const std::string& name)
	{
		auto found = std::find_if(m_map.begin(), m_map.end(),
			[=](StudentGrade& student) {return student.name == name; });
		if (found == m_map.end())
		{
			m_map.push_back(StudentGrade{ name });
			return m_map.back().grade;
		}
		else return (*found).grade;
	}

private:
	std::vector<StudentGrade> m_map;
};