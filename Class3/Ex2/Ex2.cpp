#include <iostream>
#include "Calculator.h"

int main()
{
    Calculator calc;
	calc.Clear();
	calc.Add(2);
	calc.Multiply(6);
	calc.Divide(3);
	calc.Add(5);
	calc.Subtract(2);
	std::cout << "Result: " << calc.GetResult() << "\n";
}

