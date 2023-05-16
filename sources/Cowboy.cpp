#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110) {}

void Cowboy::shoot(Character *other)
{
	return;
}

bool Cowboy::hasBullets() const
{
	return false;
}

void Cowboy::reload()
{
	return;
}

string Cowboy::print() const
{
	return "";
}