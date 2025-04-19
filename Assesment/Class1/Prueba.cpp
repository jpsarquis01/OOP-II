#include <iostream>

void OP1()
{
	system("cls");
	int userImputt;
	bool a = false;

	while (!a)
	{
		std::cout << "Select the correct answer\n\n";
		std::cout << "1 + 1 = ?\n";
		std::cout << "1. 2\n";
		std::cout << "2. 3\n";
		std::cout << "3. 100\n";
		std::cin >> userImputt;

			if (userImputt == 1)
			{
				std::cout << "Yuppie!!\n\n";
				a = true;
				break;
			}
			else
			{
				std::cout << "no\n\n";
			}
	}
}

void OP2()
{

}

int main()
{
	int userImput;

	std::cout << "Select a number:\n";
	std::cout << "1. Math\n";
	std::cout << "2. Luck\n";

	std::cin >> userImput;

	switch (userImput)
	{
	case  1:
		OP1();
		break;

	case 2:
		OP2();
		break;

	default:
		break;
	}

	return 0;
}