#include "Command.h"
#include "Commands.h"

namespace Zork
{
	void QuitCommand::execute(Player& player)
	{
		player.Quit();
	}
	void LookCommand::execute(Player& player)
	{
		player.Look();
	}
	void NorthCommand::execute(Player& player)
	{
		player.Move(Commands::NORTH);
	}
	void EastCommand::execute(Player& player)
	{
		player.Move(Commands::EAST);
	}
	void SouthCommand::execute(Player& player)
	{
		player.Move(Commands::SOUTH);
	}
	void WestCommand::execute(Player& player)
	{
		player.Move(Commands::WEST);
	}
	void UpCommand::execute(Player& player)
	{
		player.Move(Commands::UP);
	}
	void DownCommand::execute(Player& player)
	{
		player.Move(Commands::DOWN);
	}

	void InventoryCommand::execute(Player& player)
	{
		player.Inventory();
	}

	void TakeCommand::execute(Player& player)
	{
		player.Take();
	}
	void DropCommand::execute(Player& player)
	{
		player.Drop();
	}
	void RewardCommand::execute(Player& player)
	{
		player.Reward();
	}
	void ScoreCommand::execute(Player& player)
	{
		player.Score();
	}
}