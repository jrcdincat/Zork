#pragma once
#include <string>
#include <unordered_set>
#include "Commands.h"
#include "World.h"

namespace Zork
{
	class Player
	{
	public: 
		Player(std::string startingLocation, World& world);
		inline std::string GetLocation() { return _location; }
		inline bool GetIsPlaying() { return _isPlaying; }
		inline void SetItemToTake(std::string itemName) { _itemToTake = itemName; }
		inline void SetItemToDrop(std::string itemName) { _itemToDrop = itemName; }
		void Quit();
		void Look();
		void Move(Commands command);
		void Take();
		void Drop();
		void Inventory();
		void Reward();
		void Score();
	
	private: 
		World& _world;
		std::unordered_set<std::string> _inventory;
		std::string _location;
		std::string _itemToTake;
		std::string _itemToDrop;
		std::int32_t _score;
		bool _isPlaying;
	};
}

