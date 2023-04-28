#include <fstream>
#include <json/json.h>
#include "Game.h"


using namespace std;
using namespace Zork;

int main()
{
#if defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	ifstream jsonStream{ R"(Content\Game.json)" };

	if (!jsonStream.good())
	{
		throw runtime_error("Could not open file!");
	}

	Json::Value root;
	jsonStream >> root;

	Game game = Game(root);
	game.Run();

	return EXIT_SUCCESS;
}
