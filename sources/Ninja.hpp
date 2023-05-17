#pragma once

#include "Character.hpp"
#include <string>

namespace ariel
{
	class Ninja : public Character
	{
		protected:
			/*
			* @brief The speed of the ninja.
			*/
			int _speed;

		public:
			/*
			* @brief Construct a new Ninja object.
			* @param name The name of the ninja.
			* @param location The starting location of the ninja.
			* @param health_points The health points of the ninja.
			* @param speed The speed of the ninja.
			*/
			Ninja(std::string name, Point location, int health_points, int speed);

			/*
			* @brief Moves the ninja to another character _speed steps closer.
			* @param other The other character.
			* @return void
			*/
			void move(Character *other);

			/*
			* @brief Slashes another character.
			* @param other The other character.
			* @return void
			* @note If the other character is alive and the distance between the two characters is less than or equal to 1, the other character is hit.
			*/
			void slash(Character *other);

			/*
			* @brief Prints the ninja.
			* @return void
			*/
			std::string print() const override;
	};

}