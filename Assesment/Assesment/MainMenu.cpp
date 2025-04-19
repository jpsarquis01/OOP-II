#include <iostream>
#include "Character.h"
#include "Fight.h"
#include "MainMenu.h"
#include <vector>

MainMenu::MainMenu()
{
}

void MainMenu::Fight(Character& character1, Character& character2)
{
	std::cout << "Fight between " << character1.getName() << " and " << character2.getName() << " begins!\n";

	while (character1.getHealth() > 0 && character2.getHealth() > 0)
	{
		std::cout << character1.getName() << " attacks " << character2.getName() << "!\n";
		character2.setDeffence(character2.getDeffence() - character1.getAttack());
		if (character2.getDeffence() > 0)
		{
			character2.setDeffence(character2.getDeffence() - character1.getAttack());
			std::cout << character2.getName() << " has " << character2.getDeffence() << " deffence left.\n";
		}
		else if (character2.getDeffence() <= 0)
		{
			character2.setHealth(character2.getHealth() - character1.getAttack());
			std::cout << character2.getName() << " has " << character2.getHealth() << " health left.\n";
		}
		if (character2.getHealth() <= 0)
		{
			std::cout << character2.getName() << " has been defeated!\n";
			std::cout << character1.getName() << " wins with\n " << character1.getHealth();
			break;
		}
		
		
		std::cout << character2.getName() << " attacks " << character1.getName() << "!\n";
		character1.setDeffence(character1.getDeffence() - character2.getAttack());
		if (character1.getDeffence() > 0)
		{
			character1.setDeffence(character1.getDeffence() - character2.getAttack());
			std::cout << character1.getName() << " has " << character1.getDeffence() << " deffence left.\n";
		}
		else if (character1.getDeffence() <= 0)
		{
			character1.setHealth(character1.getHealth() - character2.getAttack());
			std::cout << character1.getName() << " has " << character1.getHealth() << " health left.\n";
		}
		if (character1.getHealth() <= 0)
		{
			std::cout << character1.getName() << " has been defeated!\n";
			std::cout << character2.getName() << " wins with\n " << character2.getHealth();
			break;
		}

		system("pause");
		system("cls");

	}

	std::cout << "Fight is over!\n";
}

void MainMenu::SelectCharacterGainXP()
{
	system("cls");
	if (characters.empty())
	{
		std::cout << "No characters have been created yet.\n";
		return;
	}

	std::cout << "Select a character to assign XP:\n";
	for (size_t i = 0; i < characters.size(); ++i)
	{
		std::cout << i + 1 << ". " << characters[i].getName() << "\n";
	}

	int choice;
	std::cout << "Enter the number of the character: ";
	std::cin >> choice;

	if (choice < 1 || choice > characters.size())
	{
		std::cout << "Invalid choice. Please try again.\n";
		return;
	}

	characters[choice - 1].assingRandomXP();

	
	system("pause");
	system("cls");
}

void MainMenu:: CreateCharacter()
{
	system("cls");

	std::string name;
	int health, attack, deffence, level;
	std::cout << "Enter character name: ";
	std::cin >> name;
	std::cout << "Enter character health: ";
	std::cin >> health;
	std::cout << "Enter character attack: ";
	std::cin >> attack;
	std::cout << "Enter character deffence: ";
	std::cin >> deffence;
	std::cout << "Enter character level: ";
	std::cin >> level;

	Character newCharacter(name, health, attack, deffence, level);
	characters.push_back(newCharacter);

	std::cout << "Character " << name << " created!\n\n";

	system("pause");
	system("cls");

}

void MainMenu::ViewCharacters()
{
	system("cls");

	if (characters.empty()) 
	{
		std::cout << "No characters have been created yet.\n";
		return;
	}

	std::cout << "Characters:\n";
	std::cout << "----------------------------\n";
	for (Character& character : characters)
	{
		std::cout << "Name: " << character.getName() << "\n";
		std::cout << "Health: " << character.getHealth() << "\n";
		std::cout << "Attack: " << character.getAttack() << "\n";
		std::cout << "Defense: " << character.getDeffence() << "\n";
		std::cout << "Level: " << character.getLevel() << "\n";
		std::cout << "-------------------------\n";
	}

	system("pause");
	system("cls");
}

void MainMenu::MainMenuLoop()
{
	int userImput = 0;

	std::cout << "Welcome to a shitty game!";
	std::cout << "\n";

	while (userImput != 5)
	{
		std::cout << "Welcome to a shitty game!";
		std::cout << "\n";
		std::cout << "Please select an option: ";
		std::cout << "\n";
		std::cout << "1. Create a character";
		std::cout << "\n";
		std::cout << "2. View characters";
		std::cout << "\n";
		std::cout << "3. GetXP";
		std::cout << "\n";
		std::cout << "4. Fight";
		std::cout << "\n";
		std::cout << "5. Exit";
		std::cout << "\n";
		std::cout << "Your choice: ";
		std::cin >> userImput;
		switch (userImput)
		{
		case 1:
			CreateCharacter();
			break;
		case 2:
			ViewCharacters();
			break;
		case 3:
			SelectCharacterGainXP();
			break;
		case 4:
			Fight(characters[0], characters[1]);
		case 5:
			std::cout << "Exiting the game. Goodbye!";
			break;
		default:
			std::cout << "Invalid choice. Please try again.";
			break;
		}
	}
	
}
