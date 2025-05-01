#include "Calculator.h"

// CPP is the DEFINITION
// H is DECLARATION

int Calculator::mResult = 0;
History Calculator::mHistory;

void Calculator::Add(int amount)
{
    mHistory.push_back(mResult);
    mResult += amount;
}

void Calculator::Sub(int amount)
{
    mHistory.push_back(mResult);
    mResult -= amount;
}

void Calculator::Mul(int amount)
{
    mHistory.push_back(mResult);
    mResult *= amount;
}

void Calculator::Div(int amount)
{
    mHistory.push_back(mResult);
    mResult /= amount;
}

int Calculator::GetResult()
{
    return mResult;
}

void Calculator::Clear()
{
    mResult = 0;
    mHistory.clear();
}

void Calculator::Undo()
{
    mResult = mHistory.back();
    mHistory.pop_back();
}
