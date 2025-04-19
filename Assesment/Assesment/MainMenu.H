#pragma once
#include <iostream>
#include "Character.h"
#include "Fight.h"

class MainMenu
{
public:
	MainMenu();
	void CreateCharacter();
	void ViewCharacters();
	void MainMenuLoop();
	void SelectCharacterGainXP();
	void Fight(Character& character1, Character& character2);

private:
	std::vector<Character> characters;

};