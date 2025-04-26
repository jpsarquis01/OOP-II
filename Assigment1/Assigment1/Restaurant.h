#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include "Table.h"
#include "Group.h

class Restaurant
{
public:
	Restaurant(int numTables);
	void AddGroup();
	void SeatGroup();
	void CheckOutGroup();
	

	void DispplayWaitList();
	void DisplayAvailableTables();
	void DisplayOccupiedTables();
	

private:


};

