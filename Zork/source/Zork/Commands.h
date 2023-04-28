#pragma once

#include <string>
#include <cstdlib>


namespace Zork
{
	enum class Commands
	{
		QUIT,
		LOOK,
		NORTH,
		EAST,
		SOUTH,
		WEST,
		UP,
		DOWN,
		INVENTORY,
		TAKE,
		DROP,
		REWARD,
		SCORE,
		UNKNOWN
	};

	Commands ToCommand(const std::string& commandString);
	
	inline char toupper(char c)
	{
		return static_cast<char>(::toupper(c));
	}
}