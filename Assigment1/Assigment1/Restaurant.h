#pragma once
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>
#include "Group.h"
#include "Person.h"

class Restaurant
{
public:
	Restaurant(int numTables = 5);

	void AddGroup(const std::list<Person>& clients);
	void StartServing(int frames = 1);
	void DisplayStatus() const;
	void Run(int maxFrames = 200);

	bool IsFull() const;
	int GetAvailableTable() const;
	std::string GetRandomFood() const;


private:
	int _numberOfTables;
	int _foodReturnFrames;
	int _nextGroupId;
	bool _isFull;
	std::vector<int> _tableOccupied;  // -1 means empty table
	std::queue<Group*> _waitList;
	std::map<int, Group*> _activeGroups;  // GroupID -> Group*
	std::map<std::string, int> _mainContact;  // Contact Name -> GroupID
	
	std::vector<std::string> _menu;

	// Helper methods
	void UpdateGroupStatus(Group* group);
	void ProcessOrders(Group* group);
	void ServeFood(Group* group);
	void ProcessPayment(Group* group);
	void FreeTable(int tableNum);

};

