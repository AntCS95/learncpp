#pragma once

#include "Random.h"
#include "Monster.h"

#include <array>
#include <string>

class Monster;

namespace MonsterGenerator {

	constexpr std::array<std::string_view, 6> names{
		"Bob",
		"Michael",
		"Steve",
		"Robert",
		"Nick",
		"John"
	};

	constexpr std::array<std::string_view, 6> roars{
		"*Gluck*",
		"*Aaah*",
		"*Rrrhhh*",
		"*Uhhh*",
		"*Boom*",
		"*Ffff*"
	};

	Monster::Type generateType() {
		return static_cast<Monster::Type>(Random::get(0,
			static_cast<int>(Monster::Type::max_monster_types)));
	}
	std::string_view generateName() {
		return names[Random::get(0, names.size()-1)];
	}
	std::string_view generateRoar() {
		return roars[Random::get(0, roars.size()-1)];
	}
	int generateHitPoints() {
		return Random::get(Monster::m_minHitPoints, Monster::m_maxHitPoints);
	}
	Monster generate() {
		return Monster(generateType(), generateName(), generateRoar(), generateHitPoints());
	}
}
