#include "FixedPoint2.h"

#include <iostream>

void quiz4()
{
	{
		FixedPoint2 a{ 34, 56 };
		std::cout << a << '\n';

		FixedPoint2 b{ -2, 8 };
		std::cout << b << '\n';

		FixedPoint2 c{ 2, -8 };
		std::cout << c << '\n';

		FixedPoint2 d{ -2, -8 };
		std::cout << d << '\n';

		FixedPoint2 e{ 0, -5 };
		std::cout << e << '\n';

		std::cout << static_cast<double>(e) << '\n';
	}

	{
		// Handle cases where the argument is representable directly
		FixedPoint2 a{ 0.01 };
		std::cout << a << '\n';

		FixedPoint2 b{ -0.01 };
		std::cout << b << '\n';

		// Handle cases where the argument has some rounding error
		FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
		std::cout << c << '\n';

		FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
		std::cout << d << '\n';

		// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
		FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
		std::cout << e << '\n';

		FixedPoint2 f{ 1.9 }; // make sure we handle single digit decimal
		std::cout << f << '\n';
	}

	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow

	//{
	//	FixedPoint2 a{ -0.48 };
	//	std::cout << a << '\n';

	//	std::cout << -a << '\n';

	//	std::cout << "Enter a number: "; // enter 5.678
	//	std::cin >> a;

	//	std::cout << "You entered: " << a << '\n';
	//}
	
}