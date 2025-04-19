#include <iostream>
#include <array>
#include <time.h>

int main()
{
	int num[15];
	srand(time(0));

	for (int i = 0; i < 15; i++)
	{
		num[i] = rand() % 100;
	}

	std::cout << "The numbers are: ";
	std::cout << "\n";
	for (int i = 0; i < 15; i++)
	{
		std::cout << num[i] << " ";
	}

	std::cout << "\n";
	std::cout << "First number: " << num[0];
	std::cout << "\n";
	std::cout << "Last number: " << num[14];

	std::cout << "\n\n";
	std::cout << "std::array\n";
	std::array<int, 15> myArray = {rand() % 100};
	std::cout << "The numbers are: ";
	std::cout << "\n";
	for (int i = 0; i < myArray.size(); i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << "\n";
	std::cout << "First number: " << myArray.front();
	std::cout << "\n";
	std::cout << "Last number: " << myArray.back();



}

