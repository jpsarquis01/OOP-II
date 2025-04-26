#pragma once
#include "Person.h"
#include <list>

class Group 
{
public:
	Group(std::list<Person> clientList);

	std::string GetContactName() const;
	std::list<Person> GetMembers();

	void SetStatus(int status);

	void SetRemainingFrames(int frames);
	void SetTableNumber(int tableNum);

	int GetStatus() const;
	int GetMemberCount() const;
	int GetTableNumber() const;
	int GetRemainingFrames() const;
	bool UpdateFrames();  // Returns true when frames countdown reaches zero
	

private:
	std::list<Person> _groupMembers;
	std::string _contactName;
	int _status;
	int _tableNumber;
	int _remainingFrames;

	//random timing values
	int _enterFrames;
	int _orderFrames;
	int _eatFrames;
};