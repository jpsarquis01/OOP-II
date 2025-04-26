#include "Calculator.h"
#include <iostream>

int Calculator::sResult = 0;

void Calculator::Add(int num)
{
	sResult += num;
}

void Calculator::Subtract(int num)
{
	sResult -= num;
}

void Calculator::Multiply(int num)
{
	sResult *= num;
}

void Calculator::Divide(int num)
{
	if (num != 0)
	{
		sResult /= num;
	}
	else
	{
		std::cerr << "Error: Division by zero!";
	}
}

int Calculator::GetResult()
{
	return sResult;
    return 0;
}

void Calculator::Clear()
{
	sResult = 0;
}
