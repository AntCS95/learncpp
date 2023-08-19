#pragma once

#include <string>
#include <string_view>
#include <iostream>


class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }

    friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
    {
        out << teacher.getName();
        return out;
    }
};