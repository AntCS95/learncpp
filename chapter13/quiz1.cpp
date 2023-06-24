#include "Point2d.h"

double distanceFrom(const Point2d& first, const Point2d& second) {
    return sqrt(pow(first.m_x - second.m_x, 2) + pow(first.m_y - second.m_y, 2));
}

void quiz1()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first,second) << '\n';
}