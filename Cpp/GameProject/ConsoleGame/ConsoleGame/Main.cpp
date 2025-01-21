#include "Game/Game.h"
#include "Level/MinesweeperLevel.h"
#include "Level/MainLevel.h"

int main()
{
    CheckMemoryLeak();
    Game game;
    //game.LoadLevel(new MinesweeperLevel(20,10, Vector2(20,10)));
    game.LoadLevel(new MainLevel());
    game.Run();
}
