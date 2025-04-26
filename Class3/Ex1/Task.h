#pragma once
#include <iostream>

const int gIncrementValue = 10;


int Add(int num)
{
	return num += gIncrementValue;
	std::cout << "Add: " << num << "\n";
}

int Subtract(int num)
{
	return num -= gIncrementValue;
	std::cout << "Subtract: " << num << "\n";	
}

