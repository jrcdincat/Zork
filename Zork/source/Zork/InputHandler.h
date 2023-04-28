#pragma once
#include "Command.h"
#include <memory>

namespace Zork
{
	class InputHandler
	{
	public :
		InputHandler(Player& player);
		void HandleInput();

	private:
		Player& _player;

		std::unique_ptr<Command> _quitCommand;
		std::unique_ptr<Command> _lookCommand;
		std::unique_ptr<Command> _northCommand;
		std::unique_ptr<Command> _eastCommand;
		std::unique_ptr<Command> _southCommand;
		std::unique_ptr<Command> _westCommand;
		std::unique_ptr<Command> _upCommand;
		std::unique_ptr<Command> _downCommand;
		std::unique_ptr<Command> _inventoryCommand;
		std::unique_ptr<Command> _takeCommand;
		std::unique_ptr<Command> _dropCommand;
		std::unique_ptr<Command> _rewardCommand;
		std::unique_ptr<Command> _scoreCommand;
	};
}

