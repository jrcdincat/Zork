#pragma once
#include <vector>
#include <unordered_map>
#include <json/json.h>
#include "Room.h"
#include "Item.h"

namespace Zork
{
	class World
	{
	public: 
		World(Json::Value& rootWorld);
		std::unordered_map<std::string, Room> Rooms;
	    std::unordered_map<std::string, Item> Items;
	};
}

