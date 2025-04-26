#pragma once

namespace Math
{
	int Add(int a, int b);
	int Sub(int a, int b);
	int Mul(int a, int b);
	int Div(int a, int b);
}

// MACROS
#define MATH_MIN(a, b) ((a < b) ? a : b) // ? means this one or that one. Explained by Greivin :)
#define MATH_MAX(a, b) ((a > b) ? a : b)
#define MAX_CLAMP(a, min, max) ((((a < min)? min : a) > max)? max : a)
#define MATH_ABS(a) ((a < 0)? -a : a)