#pragma once



class Calculator
{
public:
	static void Add(int num);
	static void Subtract(int num);
	static void Multiply(int num);
	static void Divide(int num);
	static int GetResult();
	static void Clear();

private:
	static int sResult;
};