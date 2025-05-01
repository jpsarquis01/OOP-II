#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Pet
{
	enum PetType { Invalid, Dog, Cat, Bird, Bunny, Fish };
	std::string name;
	int age;
	const int ID;

	// Constructor to initialize the pet
	Pet (PetType petType, std::string petName, int petAge, int petID)
		: name(petName), age(petAge), ID(petID)
	{

	}

};

class PetRegistry
{
public:
	//Singleton access
	static PetRegistry& getInstance()
	{
		static PetRegistry instance;
		return instance;
	}

	int RegisterPet(Pet::PetType petType, std::string& petName, int petAge)
	{
		// Check if pet name is empty
		int currentID = nextID++;
		pets.emplace_back(petType, petName, petAge, currentID);

		//Prints out new added pet name and ID
		std::cout << "Pet added: " << petName << " with ID: " << currentID << "\n";

		// Changes pet type enum to string
		switch (petType)
		{
		case Pet::Dog:
			std::cout << "Dog registered\n";
			break;
		case Pet::Cat:
			std::cout << "Cat registered\n";
			break;
		case Pet::Bird:
			std::cout << "Bird registered\n";
			break;
		case Pet::Bunny:
			std::cout << "Bunny registered\n";
			break;
		case Pet::Fish:
			std::cout << "Fish registered\n";
			break;
		default:
			break;
		}

		std::cout << "-------------------------\n";
		std::cout << "Pet name: " << petName << "\n";
		std::cout << "Pet age: " << petAge << "\n";
		std::cout << "------------------------\n";

		return currentID;
	
	}

	// Gets a pet by ID (Returns NULL if theres no match)
	const Pet* GetPet(int id) const
	{
		for (const auto& pet : pets)
		{
			if (pet.ID == id)
			{
				return &pet;
			}
		}
		return nullptr; // Return nullptr if not found
	}



private:
	//Constructor for singleton
	PetRegistry() : nextID(1)
	{

	}

	PetRegistry(const PetRegistry&) = delete; // Prevent copy
	PetRegistry& operator= (const PetRegistry&) = delete; // Prevent assignment

	std::vector<Pet> pets;
	int nextID;

	
};