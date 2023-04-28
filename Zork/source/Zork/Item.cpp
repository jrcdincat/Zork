#include "Item.h"

namespace Zork
{
	Item::Item(Json::Value& rootItem) : _name{ rootItem["Name"].asString() },
		_lookDescription{ rootItem["LookDescription"].asString() }, 
		_inventoryDescription{ rootItem["InventoryDescription"].asString() }
	{
	}
}