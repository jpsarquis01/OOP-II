#pragma once
#include <string>
#include <iostream>
#include <vector>

class Character
{
public:
	Character(std::string name, int health, int attack, int deffence, int level);

	int getLevel();
	int getHealth();
	int getAttack();
	int getDeffence();
	std::string getName();

	void setHealth(int newhealth);
	void setDeffence(int newdeffence);
	void assingRandomXP();

	std::string name;
	int health;
	int attack;
	int deffence;
	int level;
};