#include "Game.h"
#include <iostream>

namespace Zork
{
	Game::Game(Json::Value& root) :
		_welcomeMessage{ root["WelcomeMessage"].asString() },
		_startingLocation{ root["StartingLocation"].asString() },
		_world{ root["World"] },
		_player{ Player(_startingLocation, _world) },
		_inputHandler{ InputHandler(_player) }
	{
	}

	void Game::Run()
	{
		std::cout << _welcomeMessage << std::endl;
		_player.Look();

		while (_player.GetIsPlaying())
		{
			_inputHandler.HandleInput();
		}

		std::cout << "Thank you for playing!\n";
	}
}