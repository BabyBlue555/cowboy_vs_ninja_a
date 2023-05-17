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
	
	 for (std::vector<Character *>::iterator i = _members.begin(); i != _members.end(); ++i) {
			delete *i;
			
		}
	_members.clear();

}


Team &Team::operator=(const Team &_otherTeam) noexcept 
{
    this->_members= _otherTeam._members;
    return *this;
}
// move constructor
Team::Team(Team &&_otherTeam) noexcept {}
// move assignment operator
Team &Team::operator=(Team &&_otherTeam) noexcept 
{
    return _otherTeam=*this;
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