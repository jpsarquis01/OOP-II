#include "Character.h"
#include <iostream>
#include <time.h>

Character::Character(std::string name, int health, int attack, int deffence, int level)
	: name(name), health(health), attack(attack), deffence(deffence), level(level) 
{

}

int Character::getLevel() 
{
	return level;
}

int Character::getHealth() 
{
	return health;
}

int Character::getAttack()
{
	return attack;
}

int Character::getDeffence()
{
	return deffence;
}

std::string Character::getName()
{
	return name;
}

void Character::setHealth(int newhealth)
{
	health = newhealth;
}

void Character::setDeffence(int newdeffence)
{
	deffence = newdeffence;
}

void Character::assingRandomXP()
{
	srand(time(0));
	int randomXP = rand() % 5 + 1; 

	std::cout << "Character " << name << " gains " << randomXP << " XP.\n";
	std::cout << "\n";

	if (randomXP == 5)
	{
		int randomNumber = rand() % 3 + 1;

		level++;
		if (randomNumber == 1)
		{
			health + 5;
		}
		else if (randomNumber == 2)
		{
			attack + 10;
		}
		else if (randomNumber == 3)
		{
			deffence + 10;
		}

		std::cout << "Your character's stats have increased! \n";
		std::cout << name << " leveled up! \n";
		std::cout << "Your character's new stats are: \n";
		std::cout << "Health: " << health << "\n";
		std::cout << "Attack: " << attack << "\n";
		std::cout << "Deffence: " << deffence << "\n";
		std::cout << "Level: " << level << "\n";
		
	}
	else
	{
		std::cout << name << " did not level up. \n";
	}
}


