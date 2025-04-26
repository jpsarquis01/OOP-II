#include "Restaurant.h"
#include "Group.h"
#include "Person.h"
#include <iostream>

Restaurant::Restaurant(int numTables)
	:_numberOfTables(numTables), _isFull(false), _nextGroupId(1)
{
	_tableOccupied.resize(numTables, -1);
	_foodReturnFrames = rand() % 3 + 1;
	_menu = 
	{
		"Niguiri", "Roll", "Miso", "Ramen", "Rice",
		"Takoyaki", "Guiosa", "Dumpling", "Salad"
	};
}

std::string Restaurant::GetRandomFood() const
{
	int index = rand() % _menu.size();
	return _menu[index];
}

bool Restaurant::IsFull() const
{
	for (int i = 0; i < _tableOccupied.size(); i++)
	{
		if (_tableOccupied[i] == -1)
		{
			return false;
		}
	}
	return true;
}

int Restaurant::GetAvailableTable() const
{
	for (int i = 0; i < _tableOccupied.size(); i++)
	{
		if (_tableOccupied[i] == -1)
		{
			return i;
		}
	}
	return -1;  // No available table
}

void Restaurant::ProcessOrders(Group* group)
{
	// random food and items 
	auto members = group->GetMembers();
	for (auto& client : members)
	{
		std::string randomFood = GetRandomFood();
		client.SetFood(randomFood);
		std::cout << client.GetName() << " ordered " << randomFood << "\n";
	}
}

void Restaurant::ServeFood(Group* group)
{
	// food is served to the table
	auto members = group->GetMembers();
	for (auto& client : members)
	{
		std::cout << client.GetName() << " received their food\n";
	}
}

void Restaurant::ProcessPayment(Group* group)
{
	int tableNum = group->GetTableNumber();
	std::cout << "Bill paid by " << group->GetContactName()
		<< " for table " << tableNum + 1 << "\n";
}

void Restaurant::FreeTable(int tableNum)
{
	if (tableNum >= 0 && tableNum < _tableOccupied.size())
	{
		_tableOccupied[tableNum] = -1;
		_isFull = false;
		std::cout << "Table " << tableNum + 1 << " is now available.\n\n";
	}
}

void Restaurant::AddGroup(const std::list<Person>& persons)
{
	Group* newGroup = new Group(persons);
	if (!IsFull())
	{
		int tableNum = GetAvailableTable();
		if (tableNum != -1)
		{
			newGroup->SetTableNumber(tableNum);
			newGroup->SetStatus(1);
			_tableOccupied[tableNum] = _nextGroupId;
			std::cout << "Group " << _nextGroupId << " with " << newGroup->GetMemberCount()
				<< " members (main contact: " << newGroup->GetContactName()
				<< ") are seatead at table " << tableNum + 1 << "\n\n";
		}
	}
	else
	{
		std::cout << "restaurant full for the moment\n";
		std::cout << "Group " << _nextGroupId << " with " << newGroup->GetMemberCount()
			<< " members (main contact: " << newGroup->GetContactName()
			<< ") added to our wait list.\n\n";
	}
	
	_mainContact[newGroup->GetContactName()] = _nextGroupId;//add group main contact

	
	_activeGroups[_nextGroupId] = newGroup;// add group to active group
	_nextGroupId++;

	
	if (newGroup->GetTableNumber() == -1)//add to waitlist 
	{
		_waitList.push(newGroup);
	}

	
	_isFull = (GetAvailableTable() == -1);//update restaurant status
}

void Restaurant::StartServing(int frames)
{
	for (int i = 0; i < frames; i++)
	{
		
		std::vector<int> groupsToRemove;// process all active groups

		for (auto& pair : _activeGroups)
		{
			auto groupId = pair.first;
			auto group = pair.second;

			if (group == nullptr || group->GetStatus() == 6)	//LEFT THE RESTAURANT
			{
				groupsToRemove.push_back(groupId);
				continue;
			}

			if (group->UpdateFrames())
			{
				UpdateGroupStatus(group);
			}
		}
		
		for (int groupId : groupsToRemove)//clean up groups that left
		{
			if (_activeGroups[groupId] != nullptr)
			{
				delete _activeGroups[groupId];
			}
			_activeGroups.erase(groupId);
		}

		// seat waiting gorups if tables are available
		while (!_waitList.empty() && !IsFull())
		{
			auto nextGroup = _waitList.front();
			_waitList.pop();

			int tableNum = GetAvailableTable();
			if (tableNum != -1)
			{
				nextGroup->SetTableNumber(tableNum);
				nextGroup->SetStatus(1);	//1 for seated
				_tableOccupied[tableNum] = _nextGroupId - 1;

				std::cout <<nextGroup->GetContactName()
					<< " group is now seated in table " << tableNum + 1 << "\n\n";
			}
			// update full status
			_isFull = (GetAvailableTable() == -1);
		}
	}
}

void Restaurant::UpdateGroupStatus(Group* group)
{
	int currentStatus = group->GetStatus();
	int tableNum = group->GetTableNumber();

	switch (currentStatus)
	{
	case 0: //WAITING FOR TABLE
		// handled in simlate()
		break;

	case 1: //SEATED
		//start ordering
		group->SetStatus(2); // ORDERING
		std::cout << "Group with contact: " << group->GetContactName() << " at table " << tableNum + 1 << " is now ordering.\n\n";
		break;

	case 2: // ORDERING
		//finished ordering and waiting for food
		ProcessOrders(group);
		group->SetStatus(3); //WAITING FOR FOOD
		group->SetRemainingFrames(_foodReturnFrames);
		std::cout << "Group with contact: " << group->GetContactName() << " at table " << tableNum + 1 << " has placed orders and is waiting for food.\n\n";
		break;

	case 3: //WAITING FOR FOOD
		//food arrives, start eating
		ServeFood(group);
		group->SetStatus(4); // EATING
		std::cout << "Food served to group with contact: " << group->GetContactName() << " at table " << tableNum + 1 << ". They start eating.\n\n";
		break;

	case 4: //EATING
		//finished eating, time to pay
		group->SetStatus(5); //PAYING
		std::cout << "Group with contact: " << group->GetContactName() << " at table " << tableNum + 1 << " has finished eating and is paying.\n\n";
		break;

	case 5: //PAYING
		//finished paying, leaving restaurant
		ProcessPayment(group);
		int tableToFree = group->GetTableNumber();
		group->SetStatus(6); //LEFT THE RESTAURANT

		if (tableToFree >= 0)	// free the table
		{
			FreeTable(tableToFree);
		}

		std::cout << "Group with contact: " << group->GetContactName() << " has paid and left the restaurant.\n\n";
		break;
	}
}

void Restaurant::DisplayStatus() const
{
	std::cout << "\n--- Restaurant Status ---\n";
	std::cout << "Tables: " << _numberOfTables << " (";
	int occupied = 0;
	for (int table : _tableOccupied)
	{
		if (table != -1) occupied++;
	}
	std::cout << occupied << " tables occupied, and " << (_numberOfTables - occupied) << " tables free)\n";

	std::cout << "Number of groups on waitlist: " << _waitList.size() << "\n";
	std::cout << "Number of active groups: " << _activeGroups.size() << "\n\n";

	std::cout << "Table status:\n";
	for (int i = 0; i < _tableOccupied.size(); i++)
	{
		std::cout << "Table " << i + 1 << ": ";
		if (_tableOccupied[i] == -1)
		{
			std::cout << "Empty\n";
		}
		else
		{
			auto it = _activeGroups.find(_tableOccupied[i]);
			if (it != _activeGroups.end() && it->second != nullptr)
			{
				std::cout << "Occupied\n";
			}
		}
	}
	std::cout << "------------------------------------------------------------\n\n";
}

void Restaurant::Run(int maxFrames)
{
	int frameCount = 0;

	while (frameCount < maxFrames)
	{
		std::cout << "\nFrame " << frameCount << " -------------------------\n";

		//random chance to add a new group
		if (rand() % 5 == 0)	// 20% chance each frame
		{
			//create a random group of 1-4 customers
			int groupSize = rand() % 4 + 1;
			std::list<Person> newClients;

			for (int i = 0; i < groupSize; i++)
			{
				std::string name = "Customer" + std::to_string(rand() % 1000); //Random Name + random number
				newClients.push_back(Person(name));
			}
			AddGroup(newClients);
		}
		// run simulation for one frame
		StartServing(1);

		// display status periodically
		if (frameCount % 5 == 0)
		{
			DisplayStatus();
		}

		//increment frame count
		frameCount++;

		//if all groups left and no more on waitlist, we can close early
		if (_activeGroups.empty() && _waitList.empty() && frameCount > 20)
		{
			std::cout << "All the customers were served. Simulation complete.\n\n";
			break;
		}
	}
	std::cout << "\nSimulation ended after " << frameCount << " frames.\n\n";

	// clean up reamaining groups
	for (auto& pair : _activeGroups)
	{
		delete pair.second;
	}
}