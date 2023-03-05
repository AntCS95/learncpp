#include "chapter3.h"

int main()
{
	int x{};
	x = readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}
