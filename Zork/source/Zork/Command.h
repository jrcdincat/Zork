#pragma once
#include "Player.h"

namespace Zork
{
	class Command
	{
	public:
		virtual ~Command() {};
		virtual void execute(Player& player) = 0;
	};

	class QuitCommand : public Command
	{
	public:
		virtual void execute(Player& player);
	};

	class LookCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class NorthCommand : public Command
	{
		virtual void execute(Player& player);

	};

	class EastCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class SouthCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class WestCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class UpCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class DownCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class InventoryCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class TakeCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class DropCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class RewardCommand : public Command
	{
		virtual void execute(Player& player);
	};

	class ScoreCommand : public Command
	{
		virtual void execute(Player& player);
	};
}

