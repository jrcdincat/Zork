#include "Commands.h"
#include <map>
#include <algorithm>

using namespace std;

namespace Zork
{
	Commands ToCommand(const string& commandString)
	{
		static const std::map<string, Commands> commandMap =
		{
			{ "QUIT", Commands::QUIT },
			{ "Q", Commands::QUIT},
			{ "EXIT", Commands::QUIT},
			{ "BYE", Commands::QUIT},
			{ "LOOK", Commands::LOOK },
			{ "L", Commands::LOOK },
			{ "NORTH", Commands::NORTH },
			{ "N", Commands::NORTH },
			{ "EAST", Commands::EAST },
			{ "E", Commands::EAST },
			{ "SOUTH", Commands::SOUTH },
			{ "S", Commands::SOUTH },
			{ "WEST", Commands::WEST },
			{ "W", Commands::WEST },
			{ "UP", Commands::UP },
			{ "U", Commands::UP },
			{ "CLIMB", Commands::UP },
			{ "DOWN", Commands::DOWN },
			{ "D", Commands::DOWN },
			{ "DESCEND", Commands::DOWN },
			{ "INVENTORY", Commands::INVENTORY },
			{ "I", Commands::INVENTORY },
			{ "TAKE", Commands::TAKE },
			{ "DROP", Commands::DROP },
			{ "REWARD", Commands::REWARD },
			{ "SCORE", Commands::SCORE },
			{ "UNKNOWN", Commands::UNKNOWN }
		};

		string uppercaseCommandString;
		uppercaseCommandString.resize(commandString.size());
		transform(commandString.begin(), commandString.end(), uppercaseCommandString.begin(), Zork::toupper);
		map<string, Commands>::const_iterator found = commandMap.find(uppercaseCommandString);
		return (found != commandMap.end() ? found->second : Commands::UNKNOWN);
	}
}