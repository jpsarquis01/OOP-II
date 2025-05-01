#pragma once

#include <vector>

using History = std::vector<int>;

class Calculator
{
public:
    static void Add(int amount);
    static void Sub(int amount);
    static void Mul(int amount);
    static void Div(int amount);
    static int GetResult();
    static void Clear();
    static void Undo();

private:
    static int mResult;
    static History mHistory;
};

//Using Task D(Calculator.h) :​
//- Add using History = std::vector<int>; ​
//- History mHistory; ​
//- Every time the calculatory is used, add the previous result value to the history​
//- When clear is called, reset the history​
//- Add function to "Undo" which will pop off the last calculation​
//Test : ​
//- Solve 12 / 3 * 4 - 15 + 8​
//- Pop twice​
//- Continue calculation with(+1 – 10)