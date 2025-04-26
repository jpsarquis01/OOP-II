#include <iostream>
#include "Task.h"

int gCount = 0;

void Increment(int num)
{
	gCount += num;
}

void Print(int num)
{
	static int sLogTracker = 0;
	std::cout << "[" << sLogTracker++ << "] Count: " << gCount << "\n";
	++sLogTracker;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
		{
			Increment(Add(i));
			Print(gCount);
		
		}
		else if (i > 5)
		{
			Increment(Subtract(i));
			Print(gCount);
		}
	}
	return 0;
}
