//#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/DemoLevel.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	/*Engine engine;
	engine.LoadLevel(new DemoLevel());
	engine.Run();*/

    Game game;
    game.LoadLevel(new DemoLevel());
    game.Run();


}