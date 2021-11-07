#include <iostream>
#include <string>

enum MonsterType
{
	OGRE,
	SKELETON,
	GOBLIN,
	ORC,
	TROLL
};

struct Monster
{
	std::string name;
	int health;
	MonsterType monsterType;
};

std::string getMonsterType(Monster monster)
{
	if (monster.monsterType == OGRE)
		return "Ogre";
	if (monster.monsterType == SKELETON)
		return "Skeleton";
	if (monster.monsterType == GOBLIN)
		return "Goblin";
	if (monster.monsterType == ORC)
		return "Orc";
	if (monster.monsterType == TROLL)
		return "Troll";
}

void printMonster(Monster monster)
{
	using namespace std;
	cout << "This " << getMonsterType(monster);
	cout << " named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
	using namespace std;
	Monster goblin = { "Jack", 546, GOBLIN };
	Monster orc = { "Bones", 16, ORC };
	printMonster(goblin);
	printMonster(orc);
	return 0;
}