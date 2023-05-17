#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
	class Team
	{
		protected:
			/*
			* @brief A pointer to the leader of the team.
			*/
			Character *_leader;

			/*
			* @brief A vector of pointers to the members of the team.
			*/
			std::vector<Character *> _members;

			/*
			* @brief The size of the team.
			*/
			int _size;

			/*
			* @brief Find a victim to attack.
			* @param other A pointer to the other team.
			* @return A pointer to the victim, or nullptr if there is no victim.
			*/
			static Character *_find_victim(Team *other);

		public:
			/*
			* @brief Construct a new Team object.
			* @param leader A pointer to the leader of the team.
			*/
			Team(Character *leader);

			/*
			* @brief Destroy the Team object.
			* @brief This is a virtual destructor because this class is inherited to other classes.
			*/
			virtual ~Team();

	
			// copy constructor
			Team(Team &);
			// copy assignment operator
			Team &operator=(const Team &) noexcept;
			// move constructor
			Team(Team &&) noexcept;
			// move assignment operator
			Team &operator=(Team &&) noexcept;
  

			/*
			* @brief Add a member to the team.
			* @param member A pointer to the member to add.
			*/
			void add(Character *member);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			virtual void attack(Team *other);

			/*
			* @brief Check if the team is still alive
			* @return int The number of alive members
			*/
			int stillAlive() const;

			/*
			* @brief Get a member of the team
			* @param index The index of the member
			* @return A pointer to the member
			*/
			Character *getMember(int index) const;

			/*
			* @brief Get the size of the team
			* @return The size of the team
			*/
			int getSize() const;

			/*
			* @brief Print the team members
			*/
			virtual void print() const;
	};

	class Team2 : public Team
	{
		public:
			/*
			* @brief Construct a new Team2 object.
			* @param leader A pointer to the leader of the team.
			*/
			Team2(Character *leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) override;

			/*
			* @brief Print the team members
			*/
			void print() const override;
	};

	class SmartTeam : public Team
	{
		public:
			/*
			* @brief Construct a new SmartTeam object.
			* @param leader A pointer to the leader of the team.
			*/
			SmartTeam(Character *leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) override;

			/*
			* @brief Print the team members
			*/
			void print() const override;
	};
}