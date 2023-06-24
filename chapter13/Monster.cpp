#include "Monster.h"

#include <iostream>

Monster::Monster(Type type, std::string_view name, std::string_view roar, int hitPoints) :
	m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
{}

std::string Monster::getTypeString() const
{
	switch (m_type) {
	case Type::dragon: return "dragon";
	case Type::goblin: return "goblin";
	case Type::ogre: return "ogre";
	case Type::orc: return "orc";
	case Type::skeleton: return "skeleton";
	case Type::troll: return "troll";
	case Type::vampire: return "vampire";
	case Type::zombie: return "zombie";
	default: return "Unknown";
	}
}

void Monster::print() const
{
	std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints
		<< " hit points and says " << m_roar << '\n';
}