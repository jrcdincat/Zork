#include "InputHandler.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Command.h"

namespace Zork
{
	InputHandler::InputHandler(Player& player): 
		_quitCommand{ new QuitCommand() },
		_lookCommand{ new LookCommand() },
		_northCommand{ new NorthCommand() },
		_eastCommand{ new EastCommand() },
		_southCommand{ new SouthCommand() },
		_westCommand{ new WestCommand() },
		_upCommand{ new UpCommand() },
		_downCommand{ new DownCommand() },
		_inventoryCommand{ new InventoryCommand() },
		_takeCommand{ new TakeCommand() },
		_dropCommand{ new DropCommand() },
		_rewardCommand{ new RewardCommand() },
		_scoreCommand{ new ScoreCommand() },
		_player { player }
	{
	}

	void InputHandler::HandleInput()
	{
		std::string inputString;
		std::string commandString;
		std::string itemString;
		std::getline(std::cin, inputString);
		std::transform(inputString.begin(), inputString.end(), inputString.begin(), Zork::toupper);

		// Separate input line into separate string variables
		std::istringstream stringStream(inputString);
		stringStream >> commandString;
		stringStream >> itemString;

		Commands command = ToCommand(commandString);
		switch (command)
		{
		case Commands::QUIT:
			_quitCommand->execute(_player);
			break;
		case Commands::LOOK:
			_lookCommand->execute(_player);
			break;
		case Commands::NORTH:
			_northCommand->execute(_player);
			break;
		case Commands::EAST:
			_eastCommand->execute(_player);
			break;
		case Commands::SOUTH:
			_southCommand->execute(_player);
			break;
		case Commands::WEST:
			_westCommand->execute(_player);
			break;
		case Commands::UP:
			_upCommand->execute(_player);
			break;
		case Commands::DOWN:
			_downCommand->execute(_player);
			break;
		case Commands::INVENTORY:
			_inventoryCommand->execute(_player);
			break;
		case Commands::TAKE:
			_player.SetItemToTake(itemString);
			_takeCommand->execute(_player);
			break;
		case Commands::DROP:
			_player.SetItemToDrop(itemString);
			_dropCommand->execute(_player);
			break;
		case Commands::REWARD:
			_rewardCommand->execute(_player);
			break;
		case Commands::SCORE:
			_scoreCommand->execute(_player);
			break;
		default:
			std::cout << "Unrecognized command.\n";
			break;
		}
	}
}