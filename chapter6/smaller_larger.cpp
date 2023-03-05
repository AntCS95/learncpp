#include <iostream>

void smallerLarger() {
	//input
	std::cout << "Enter an integer: ";
	int smaller{};
	std::cin >> smaller;
	std::cout << "Enter a larger integer: ";
	int larger{};
	std::cin >> larger;
	//check
	if (smaller > larger) {
		int temp{ larger };
		larger = smaller;
		smaller = temp;
	}
	//print
	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';
}