#include <string>
#include <iostream>

class Ball {
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };
public:
	Ball() = default;
	Ball(std::string color) {
		m_color = color;
	}
	Ball(double radius) {
		m_radius = radius;
	}
	Ball(std::string color, double radius) {
		m_color = color;
		m_radius = radius;
	}
	void print() {
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void testBallClass()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
	int(x);
}