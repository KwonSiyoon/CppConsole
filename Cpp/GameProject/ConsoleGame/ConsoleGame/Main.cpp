#include "Game/Game.h"
#include "Level/MinesweeperLevel.h"

int main()
{
    Game game;
    game.LoadLevel(new MinesweeperLevel());
    game.Run();
}
