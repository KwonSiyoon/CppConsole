#include "Game/Game.h"
#include "Level/MinesweeperLevel.h"

int main()
{
    CheckMemoryLeak();
    Game game;
    game.LoadLevel(new MinesweeperLevel(60,20));
    game.Run();
}
