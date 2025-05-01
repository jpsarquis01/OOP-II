
#include <iostream>
#include "Globals.h"
#include "Calculator.h"
#include "Math.h"
#include "Constants.h"
#include "GameManager.h"

#include <vector>
#include <unordered_map>

int gCount = 0;

void Increment(int amount)
{
    gCount += amount;
}

void Print(int value)
{
    static int sLogTracker = 0;
    std::cout << "[" << sLogTracker << "] Print: [" << value << "]\n";
    ++sLogTracker;
}

int main()
{
    //for (int i = 0; i < 10; ++i)
    //{
    //    if (i < 5)
    //    {
    //        Increment(GetSum(i));
    //    }
    //    else
    //    {
    //        Increment(GetDifference(i));
    //    }
    //    Print(gCount);
    //}
    //Print(gCount);


    //- Solve the equation 2 * 6 / 3 + 5 – 2 (hint, first call should be Add(2))​
    // ClassName::Function() for static functions
    //Calculator::Clear();
    //Calculator::Add(2);
    //Calculator::Mul(6);
    //Calculator::Div(3);
    //Calculator::Add(5);
    //Calculator::Sub(2);
    //Print(Calculator::GetResult());


    ////Solve the equation(32 / 8)* (2 + 3) - 13​
    //int div = Math::Div(32, 8);
    //int add = Math::Add(2, 3);
    //int mul = Math::Mul(div, add);
    //int res = Math::Sub(mul, 13);
    //Print(res);

    //int add = Math::Add(10, 3);
    //Print(add);
    //int sub = Math::Sub(25, 30);
    //Print(sub);
    //int mul = Math::Mul(11, 24);
    //Print(mul);
    //int div = Math::Div(75, 15);
    //Print(div);

    //for (int i = 0; i < 5; ++i)
    //{
    //    Print(MATH_MIN(rand() % 10, rand() % 10));
    //    Print(MATH_MAX(rand() % 10, rand() % 10));
    //    Print(MATH_CLAMP(rand() % 10, 2, 5));
    //    Print(MATH_ABS(((rand() % 10) - 5)));
    //}

    //Print the result of 2 * kPi * 5​
    //Print the result of 90 * kDegToRad​
    //Print the result of 1.5708 * kRadToDeg

    //float circ = 2.0f * Constants::kPi * 5.0f;
    //std::cout << "Circumference: " << circ << "\n";

    //float rad = 90.0f * Constants::kDegToRad;
    //std::cout << "Rad: " << rad << "\n";

    //float deg = 1.5708f * Constants::kRadToDeg;
    //std::cout << "Deg: " << deg << "\n";


//- Solve 12 / 3 * 4 - 15 + 8​
//- Pop twice​
//- Continue calculation with(+1 – 10)
    //Calculator::Add(12);
    //Calculator::Div(3);
    //Calculator::Mul(4);
    //Calculator::Sub(15);
    //Calculator::Add(8);
    //Print(Calculator::GetResult());
    //Calculator::Undo();
    //Calculator::Undo();
    //Print(Calculator::GetResult());
    //Calculator::Add(1);
    //Calculator::Sub(10);
    //Print(Calculator::GetResult());

    GameManager::Get()->Initialize();
    GameManager::Get()->Update();
    GameManager::Get()->Terminate();

    GameManager* gm = GameManager::Get();
    gm->Initialize();
    gm->Update();
    gm->Terminate();


    return 0;
}