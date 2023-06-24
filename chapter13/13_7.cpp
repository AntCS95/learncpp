#include <iostream>
#include <string>
#include <string_view>

class Ball2
{
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:
	// Default constructor with no parameters
	Ball2()
	{
	}

	// Constructor with only color parameter (radius will use default value)
	Ball2(std::string_view color): m_color{color}
	{
	}

	// Constructor with only radius parameter (color will use default value)
	Ball2(double radius): m_radius{radius}
	{
	}

	// Constructor with both color and radius parameters
	Ball2(std::string_view color, double radius):
		m_color{color}, m_radius{radius}
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void testBall2Class()
{
	Ball2 def;
	def.print();

	Ball2 blue{ "blue" };
	blue.print();

	Ball2 twenty{ 20.0 };
	twenty.print();

	Ball2 blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
}