#pragma once

#include "Teacher.h"

#include <vector>
#include <functional>
#include <iostream>

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers;

public:
    Department() = default;
    void add(const Teacher& teacher)
    {
        m_teachers.push_back(teacher);
    }
    friend std::ostream& operator<<(std::ostream& out, const Department& department)
    {
        for (const Teacher& teacher : department.m_teachers)
        {
            out << teacher << '\n';
        }
        return out;
    }
};