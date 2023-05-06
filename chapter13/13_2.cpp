#include <iostream>

class IntPair
{
public:
	int _x{};
	int _y{};
	void print() {
		std::cout << "Pair(" << _x << ", " << _y << ")\n";
	}
	void set(int x, int y) {
		_x = x;
		_y = y;
	}
};

void testPairClass()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();
}