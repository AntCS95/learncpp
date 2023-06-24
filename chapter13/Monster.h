#pragma once

#include <string>

class Monster {

public:

	enum class Type {
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

	static constexpr int m_minHitPoints{ 1 };
	static constexpr int m_maxHitPoints{ 100 };

private:

	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

	std::string getTypeString() const;

public:

	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints);
	void print() const;

};