#pragma once

#include <iostream>
#include <cmath>

class Point2d {
private:
	double m_x{};
	double m_y{};
public:
	Point2d(double x=0., double y=0.) : m_x{x}, m_y{y} {}
	void print() {
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}
	double distanceTo(const Point2d& toPoint) const {
		return sqrt(pow(m_x - toPoint.m_x, 2) + pow(m_y - toPoint.m_y, 2));
	}
	friend double distanceFrom(const Point2d& first, const Point2d& second);
};