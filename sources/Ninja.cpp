#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int health_points, int speed) : Character(name, location, health_points), _speed(speed) {}

void Ninja::move(Character *other)
{
	return;
}

void Ninja::slash(Character *other)
{
	return;
}

string Ninja::print() const
{
	return "";
}

// YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {}

// TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {}

// OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 140, 8) {}