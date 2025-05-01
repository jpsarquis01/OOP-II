#pragma once

namespace Math
{
    inline int Add(int a, int b)
    {
        return a + b;
    }
    inline int Sub(int a, int b)
    {
        return a - b;
    }
    inline int Mul(int a, int b)
    {
        return a * b;
    }
    inline int Div(int a, int b)
    {
        return a / b;
    }
}

#define MATH_MIN(a, b) ((a < b) ? a : b)
#define MATH_MAX(a, b) ((a > b) ? a : b)
#define MATH_CLAMP(a, min, max) ((((a < min)? min : a) > max)? max : a)
#define MATH_ABS(a) ((a < 0)? -1 * a : a)


//Can add macros to the Math.h file in Task E​
//Create functions : ​
//- MATH_MIN(a, b) - returns the smallest of the two numbers​
//- MATH_MAX(a, b) - returns the largest of the two numbers​
//- MATH_CLAMP(a, min, max) - returns the value in the range or the min / max​
//- MATH_ABS(a) - returns a values that is always positive​
//Test​
//- Run each function 5 times with random numbers between 1 - 10 and print out the results