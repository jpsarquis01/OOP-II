#include "Group.h"
#include "Person.h"
#include "Restaurant.h"
#include <list>
#include <string>

Group::Group(std::list<Person> clientList)
    :_groupMembers(clientList), _status(0), _tableNumber(-1), _remainingFrames(0)
{
    if (!_groupMembers.empty())
    {
        _contactName = _groupMembers.front().GetName();
    }
    _enterFrames = rand() % 3 + 1;
    _orderFrames = rand() % 3 + 1;
    _eatFrames = rand() % 3 + 1;
}

std::string Group::GetContactName() const
{
    return _contactName;
}

std::list<Person> Group::GetMembers()
{
    return _groupMembers;
}

int Group::GetStatus() const
{
    return _status;
}

int Group::GetMemberCount() const
{
    return _groupMembers.size();
}

void Group::SetTableNumber(int tableNum)
{
    _tableNumber = tableNum;
}

int Group::GetTableNumber() const
{
    return _tableNumber;
}

int Group::GetRemainingFrames() const
{
    return _remainingFrames;
}

void Group::SetRemainingFrames(int frames)
{
    _remainingFrames = frames;
}

bool Group::UpdateFrames()
{
    if (_remainingFrames > 0)
    {
        _remainingFrames--;
    }
    return (_remainingFrames <= 0);
}

void Group::SetStatus(int status)
{
    _status = status;

    switch (_status)
    {
	case 0: // In waiting list
        _remainingFrames = _enterFrames;
        break;
    case 1: // In table
        _remainingFrames = 0;
        break;
    case 2: // Geting food
        _remainingFrames = _orderFrames;
        break;
    case 4: // Eating
        _remainingFrames = _eatFrames;
        break;
    default:
        break;
    }
}