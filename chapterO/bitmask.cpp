#include <bitset>
#include <cstdint>
#include <iostream>

void bitMask() {
	[[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
	[[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
	[[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
	[[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
	[[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

	std::uint8_t myArticleFlags{ option_favorited };

	//set article as viewed (using viewed mask)
	myArticleFlags |= option_viewed;
	std::cout << std::bitset<8>{ myArticleFlags } << '\n';
	//check if article was deleted
	std::cout << "Deleted: " << std::boolalpha << static_cast<bool>(myArticleFlags & option_deleted) << '\n';
	//clear as favourite
	myArticleFlags &= ~option_favorited;
	std::cout << std::bitset<8>{ myArticleFlags } << '\n';
}