#pragma once

#include "Character.hpp"

namespace ariel
{
	class Cowboy : public Character
	{
		private:
			/*
			* @brief The number of bullets the cowboy has.
			*/
			int _bullets;

		public:
			/*
			* @brief Construct a new Cowboy object.
			* @param name The name of the cowboy.
			* @param location The starting location of the cowboy.
			*/
			Cowboy(std::string name, Point location);

			/*
			* @brief default constructor, gererates two random doubles as a Point
			*/
			Cowboy();

			/*
			* @brief Shoots another character.
			* @param other The other character.
			* @return void
			* @note If the other character is alive and the distance between the two characters is less than or equal to 10, the other character is hit.
			*/
			void shoot(Character *other);

			/*
			* @brief Checks if the cowboy has bullets.
			* @return True if the cowboy has bullets, false otherwise.
			*/
			bool hasboolets() const;

			/*
			* @brief Reloads the cowboy's gun back to 6 bullets.
			* @return void
			*/
			void reload();

			/*
			* @brief Prints the cowboy.
			* @return void
			*/
			std::string print() const override;
	};
}