#pragma once
#include <json/json.h>
#include <string>

namespace Zork
{
	class Item
	{
	public: 
		Item(Json::Value& rootItem);
		inline std::string GetLookDescription() { return _lookDescription; }
		inline std::string GetInventoryDescription() { return _inventoryDescription; }
	private:
		const std::string _name;
		const std::string _lookDescription;
		const std::string _inventoryDescription;
	};
}

