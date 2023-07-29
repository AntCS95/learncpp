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
		std::cout << f;
	}
	
}