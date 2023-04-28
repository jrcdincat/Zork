#include "World.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include "Commands.h"

namespace Zork
{
	World::World(Json::Value& rootWorld)
	{
		Items.reserve(rootWorld["Items"].size());
		for (Json::Value item : rootWorld["Items"])
		{
			std::string itemName = item["Name"].asString();
			transform(itemName.begin(), itemName.end(), itemName.begin(), Zork::toupper);
			Items.emplace(itemName, Item(item));
		}

		Rooms.reserve(rootWorld["Rooms"].size());
		for (Json::Value room : rootWorld["Rooms"])
		{
			Rooms.emplace(room["Name"].asString(), Room(room));
		}
	};
}
