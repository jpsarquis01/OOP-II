#include <iostream>

int gCount = 0;

void Increment(int num)
{
	gCount += num;
}

void Print(int num)
{
	std::cout << "Count: " << gCount << "\n";
}

int main()
{
	// ++i = 1 >> i;
	// i++ = i + 1;
	for (int i = 0; i < 10; ++i)
	{
		Increment(10);
		Print(gCount);
		std::cout << "\n";
	}
	return 0;
}

