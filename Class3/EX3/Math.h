#pragma once
#define MATH_MIN(a, b)((a < b) ? a : b) //- returns the smallest of the two numbers
#define MATH_MAX(a, b)((a > b) ? a : b) //- returns the largest of the two numbers
#define MATH_CLAMP(a, min, max)((((a < min) ? min : a) > max)? max : a)//- returns the value in the range or the min/max
#define MATH_ABS(a)((a < 0)? -a : a)//- returns the value that is always positive

#define SET_TYPE_ID(id)\
static

namespace Math
{
	int Add(int num, int num2);
	int Subtract(int num, int num2);
	int Multiply(int num, int num2);
	int Divide(int num, int num2);
	int GetResult();
	void Clear();
}