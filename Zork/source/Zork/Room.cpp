#include "Room.h"
#include <iostream>
#include <algorithm>
#include "Commands.h"

namespace Zork
{
	Room::Room(Json::Value& rootRoom) : 
		_name{ rootRoom["Name"].asString() }, _description{ rootRoom["Description"].asString() }
	{
		Json::Value neighborsRoot = rootRoom["Neighbors"];
		for (Json::ValueIterator iterator = neighborsRoot.begin(); iterator != neighborsRoot.end(); ++iterator)
		{
			 std::string key = iterator.key().asString();
			 _neighbors.emplace(key, neighborsRoot[key].asString());
		}

		Json::Value inventoryNamesRoot = rootRoom["InventoryNames"];
		for (Json::Value inventoryName : inventoryNamesRoot)
		{	
			std::string inventoryKey = inventoryName.asString();
			transform(inventoryKey.begin(), inventoryKey.end(), inventoryKey.begin(), Zork::toupper);
			_inventoryNames.emplace(inventoryKey);
		}
	}
}