#pragma once
#include <json/json.h>
#include <string>
#include "World.h"
#include "Player.h"
#include "InputHandler.h"

namespace Zork
{
	class Game
	{
	public: 
		Game(Json::Value& root);
		void Run();

	private: 
		const std::string _welcomeMessage;
		const std::string _startingLocation;
		World _world;
		Player _player;
		InputHandler _inputHandler;
	};
}

