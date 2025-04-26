#include "Person.h"
#include <string>

Person::Person(std::string name)
	:_customerName(name), _customerFood("")
{
}

void Person::SetFood(std::string food)
{
	_customerFood = food;
}

std::string Person::GetName() const
{
	return _customerName;
}

std::string Person::GetFood() const
{
	return _customerFood;
}