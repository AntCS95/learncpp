/*
a) First, let’s create an enumeration of monster types named MonsterType.
Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton,
Troll, Vampire, and Zombie. Add an additional max_monster_types enum so we can
count how many enumerators there are.
 
b) Now, let’s create our Monster class. Our Monster will have 4 attributes
(member variables): a type (MonsterType), a name (std::string),
a roar (std::string), and the number of hit points (int).
Create a Monster class that has these 4 member variables.

c) enum MonsterType is specific to Monster, so move the enum inside the class
as a public declaration. When the enum is inside the class, “MonsterType” can
be renamed “Type” since the context is already Monster.

d) Create a constructor that allows you to initialize all of the member variables.

e) Now we want to be able to print our monster so we can validate it’s correct.
To do that, we’re going to need to write a function that converts a
Monster::Type into a string. Write that function (called getTypeString()),
as well as a print() member function. Example:
Bones the skeleton has 4 hit points and says *rattle*

f) Now we can create a random monster generator. Let’s consider how our
monster generator will work. Ideally, we’ll ask it to give us a Monster,
and it will create a random one for us. We don’t need more than one
monster generator, and we are not maintaining any state, so this is a good
candidate for a namespace. Create a namespace named MonsterGenerator.
Create a function named generate() that returns a Monster. For now, make it
return anonymous Monster { Monster::Type::skeleton, "Bones", "*rattle*", 4 };

g) Now, MonsterGenerator needs to generate some random attributes.
To do that, first copy and save the “Random.h” header from
lesson 7.20 -- Generating random numbers using Mersenne Twister to your project.

Modify the function generate() from the prior quiz to generate a random
Monster::Type (between 0 and Monster::Type::max_monster_types-1) and a random
hit points (between 1 and 100). This should be fairly straightforward.

Once you’ve done that, define two static fixed arrays of size 6 inside the
function (named s_names and s_roars) and initialize them with6 names and
6 sounds of your choice. Pick a random name and roar from these arrays.

*/

#include "Monster.h"
#include "MonsterGenerator.h"

void quiz3()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();
}