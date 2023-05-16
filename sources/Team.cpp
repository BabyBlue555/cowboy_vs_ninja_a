#include "Team.hpp"

using namespace std;
using namespace ariel;

Character *Team::_find_victim(Team *other)
{
	return nullptr;
}

Team::Team(Character *leader) : _leader(leader), _size(1)
{
	_members.push_back(leader);
}

Team::~Team()
{
	Cowboy *c = nullptr;
	Ninja *n = nullptr;

	while (_members.size() > 0)
	{
		Character *tmp = _members.back();
		_members.pop_back();
		
		c = dynamic_cast<Cowboy *>(tmp);
		n = dynamic_cast<Ninja *>(tmp);

		if (c != nullptr)
		{
			delete c;
		}

		else if (n != nullptr)
		{
			delete n;
		}
	}
}

void Team::add(Character *member)
{
	return;
}

void Team::attack(Team *other)
{
	return;
}

int Team::stillAlive() const
{
	return 0;
}

Character *Team::getMember(int index) const
{
	return nullptr;
}

int Team::getSize() const
{
	return 0;
}

void Team::print() const
{
	return;
}

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *other)
{
	return;
}

void Team2::print() const
{
	return;
}

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void SmartTeam::attack(Team *other)
{
	return;
}

void SmartTeam::print() const
{
	return;
}