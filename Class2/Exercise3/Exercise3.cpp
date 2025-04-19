#include <iostream>
#include <array>
#include <time.h>
#include <vector>

int main()
{
	srand(time(0));

	//Int* with 20 elements and random values
	int* numbers = new int[20];
	for (int i = 0; i < 20; i++)
	{
		numbers[i] = rand() % 100;
	}

	//Print the array
	std::cout << "First 20 elements: " << "\n";
	for (int i = 0; i < 20; i++)
	{
		std::cout << numbers[i] << ", ";
	}

	std::cout << "\n";

	//Resize the array to 21 elements with the same og values and a new random value
	int* temp = new int[21];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = numbers[i];
	}
	temp[20] = rand() % 100; //Assign a new random value to the new element
	delete[] numbers; //Delete the old array
	numbers = temp;

	std::cout << "\n";

	//Print the new array
	std::cout << "New array with 21 elements: " << "\n";
	for (int i = 0; i < 21; i++)
	{
		std::cout << numbers[i] << ", ";
	}

	std::cout << "\n";
	std::cout << "\n";

	//Resize the array to 30 elements with the same og values and new random values 
	temp = new int[30];
	for (int i = 0; i < 21; i++)
	{
		temp[i] = numbers[i];
	}
	for (int i = 21; i < 30; i++)
	{
		temp[i] = rand() % 100; //Assign a new random value to the new element
	}

	delete[] numbers; //Free the old array
	numbers = temp;

	//Print the new array
	std::cout << "New array with 30 elements: " << "\n";
	for (int i = 0; i < 30; i++)
	{
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n\n";

	delete[] numbers; //Free the array

	//The same but now in vector --------------------------------------
	std::cout << "---------------------------------------------------------------------\n\n";

	 //Create a vector with 20 elements and assign random values
	std::vector<int> numberss(20);
	for (int i = 0; i < 20; i++) 
	{
		numberss[i] = rand() % 100; 
	}

	//Print the initial 20 elements
	std::cout << "First 20 elements: " << "\n";
	for (int i = 0; i < 20; i++) 
	{
		std::cout << numberss[i] << ", ";
	}
	std::cout << "\n";

	//Resize the vector to 21 elements and assign a random value to the new element
	numberss.resize(21);
	numberss[20] = rand() % 100; 

	//Print the new vector with 21 elements
	std::cout << "\nNew vector with 21 elements: " << "\n";
	for (int i = 0; i < 21; i++) 
	{
		std::cout << numberss[i] << ", ";
	}
	std::cout << "\n";

	//Resize the vector to 30 elements and assign random values to the new elements
	numberss.resize(30);
	for (int i = 21; i < 30; i++) 
	{
		numberss[i] = rand() % 100; 
	}

	//Print the new vector with 30 elements
	std::cout << "\nNew vector with 30 elements: " << "\n";
	for (int i = 0; i < 30; i++)
	{
		std::cout << numberss[i] << ", ";
	}
	std::cout << "\n";


	return 0;

}

