#include <iostream>
#include <string>

struct Pet
{
	enum PetType { Invalid, Dog, Cat, Bird, Bunny, Fish };
	std::string name;
	int age;
	const int ID;
	
};

int main()
{
    std::cout << "Hello World!\n";
}

