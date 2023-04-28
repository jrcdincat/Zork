#include "Player.h"
#include <iostream>
#include <unordered_set>

namespace Zork
{
	Player::Player(std::string startingLocation, World& world) :
		_world{ world },
		_location{ startingLocation },
		_score{ 0 },
		_isPlaying{ true }

	{
	}
	void Player::Quit()
	{
		_isPlaying = false;
	}
	void Player::Look()
	{
		Room& room = _world.Rooms.at(_location);
		std::cout << room.GetDescription() << std::endl;
		for (auto& item : room._inventoryNames)
		{
			if (!_world.Items.contains(item))
			{
				continue;
			}

			std::cout << _world.Items.at(item).GetLookDescription() << std::endl;
		}
	}
	void Player::Move(Commands command)
	{
		switch (command)
		{
		case Commands::NORTH:
			if (_world.Rooms.at(_location)._neighbors.contains("North"))
			{
				_location =_world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("North")).GetName();
			}
			break;
		case Commands::EAST:
			if (_world.Rooms.at(_location)._neighbors.contains("East"))
			{
				_location = _world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("East")).GetName();
			}
			break;
		case Commands::SOUTH:
			if (_world.Rooms.at(_location)._neighbors.contains("South"))
			{
				_location = _world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("South")).GetName();
			}
			break;
		case Commands::WEST:
			if (_world.Rooms.at(_location)._neighbors.contains("West"))
			{
				_location = _world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("West")).GetName();
			}
			break;
		case Commands::UP:
			if (_world.Rooms.at(_location)._neighbors.contains("Up"))
			{
				_location = _world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("Up")).GetName();
			}
			break;
		case Commands::DOWN:
			if (_world.Rooms.at(_location)._neighbors.contains("Down"))
			{
				_location = _world.Rooms.at(_world.Rooms.at(_location)._neighbors.at("Down")).GetName();
			}
			break;
		}
		std::cout << _location << std::endl;
	}

	void Player::Inventory()
	{
		if (_inventory.empty())
		{
			std::cout << "You are empty handed." << std::endl;
			return;
		}

		std::cout << "You are carrying." << std::endl;
		for (auto& item : _inventory)
			std::cout << _world.Items.at(item).GetInventoryDescription() << std::endl;
	}
	void Player::Take()
	{
		std::unordered_set<std::string>& inventoryNames = _world.Rooms.at(_location)._inventoryNames;
		if (!inventoryNames.contains(_itemToTake))
		{
			std::cout << "You can't see any such thing." << std::endl;
			return;
		}

		_inventory.emplace(_itemToTake);
		inventoryNames.erase(_itemToTake);
		std::cout << "Taken."<< std::endl;
	}
	void Player::Drop()
	{
		if (!_inventory.contains(_itemToDrop))
		{
			std::cout << "You are not carrying any such thing." << std::endl;
			return;
		}
		_world.Rooms.at(_location)._inventoryNames.emplace(_itemToDrop);
		_inventory.erase(_itemToDrop);
		std::cout << "Dropped." << std::endl;
	}
	void Player::Reward()
	{
		_score++;
	}
	void Player::Score()
	{
		std::cout << _score << std::endl;
	}
}