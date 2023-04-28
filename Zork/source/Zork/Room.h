#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <json/json.h>

namespace Zork
{
	class Room
	{
	public: 
		Room(Json::Value& rootRoom);
		inline std::string GetName() { return _name; }
		inline std::string GetDescription() { return _description; }
		std::unordered_map<std::string, std::string> _neighbors;
		std::unordered_set<std::string> _inventoryNames;

	private: 
		const std::string _name;
		const std::string _description;
	};
}