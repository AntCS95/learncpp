#include <bitset>
#include <iostream>

//std::bitset<4> rotl(std::bitset<4> bits) {
//	bool bit{ bits.test(3) };
//	bits <<= 1;
//	if (bit) bits.set(0);
//	return bits;
//}

std::bitset<4> rotl(std::bitset<4> bits) {
	return (bits << 1) | (bits >> 3);
}

void rotlTest() {
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';
}