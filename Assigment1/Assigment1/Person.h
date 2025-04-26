#pragma once
#include <iostream>
#include <string>

class Person
{
public:
	Person(std::string name);
	void SetFood(std::string food);

	std::string GetName() const;
	std::string GetFood() const;


private:
	std::string _customerName;
	std::string _customerFood;
};