//#include "Point.hpp"

#include "Character.hpp"

#include <cmath>
using namespace std;
using namespace ariel;



Character::Character(string name, Point &location, int health_points) : _name(name), _location(location), _hp(health_points), _inteam(false) {}

bool Character::isAlive() const{
	return 1;
}


// Character::Character(Character &_otherChar) noexcept=delete;
// copy assignment operator
Character &Character::operator=(const Character &_otherChar) noexcept
{
    this->_location = _otherChar._location;
    this->_hp = _otherChar._hp;
    this->_name = _otherChar._name;
    return *this;
}
// move constructor
// Character::Character(Character &&_otherChar) noexcept =delete;
// move assignment operator
Character &Character::operator=(Character &&_otherChar) noexcept
{
    return _otherChar = *this;
}
// destructor
Character::~Character() {}


double Character::distance(Character *other) const
{
	return 0.0;
}

void Character::hit(int power)
{
	return;
}

string Character::getName() const
{
	return "";
}

void Character::setName(std::string){
	
}

const Point& Character::getLocation() const
{
	return _location;
}

void Character::setLocation(Point &location)
{
	return;
}

bool Character::isInTeam() const
{
	return false;
}

void Character::setInTeam(bool in_team)
{
	return;
}

int Character::getHP() const
{
	return 0;
}

void Character::setHP(int){

}



 