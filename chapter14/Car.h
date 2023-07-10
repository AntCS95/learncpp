#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend bool operator< (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')';
    return out;
}

bool operator< (const Car& c1, const Car& c2)
{
    if (c1.m_make != c2.m_make)
    {
        return c1.m_make < c2.m_make;
    }
    else
    {
        return c1.m_model < c2.m_model;
    }
}