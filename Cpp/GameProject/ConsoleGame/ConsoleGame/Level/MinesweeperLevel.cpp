#include "MinesweeperLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"
#include "Actor/Mine.h"
#include "Actor/MineIndicator.h"
#include "Actor/Empty.h"
#include "Actor/Wall.h"
#include "Actor/UnopenedCell.h"
#include <Windows.h>

MinesweeperLevel::MinesweeperLevel(int xSize, int ySize)
{
    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);
    
    
    if (xSize != 0 && ySize != 0)
    {
        gameSize = Vector2(xSize, ySize);
    }
    
    int totalSizeX = gameSize.x + 3; // 벽 2칸 + 개행 1칸.
    int totalSizeY = gameSize.y + 2; // 벽 2칸.
    Vector2 startPos = Vector2(2, 2);
    //Engine::Get().SetCursorPosition(startPos);
    // 벽 만들기. Actor 인스턴스 생성.
    for (int y = 0; y <= totalSizeY; ++y)
    {
        for (int x = 0; x <= totalSizeX; ++x)
        {
            if (x == totalSizeX)
            {
                Engine::Get().SetCursorPosition(Vector2(x,y));
                std::cout << ' ';
                continue;
            }
            if (y == 0 || y == totalSizeY || x == 0 || x== totalSizeX-1)
            {
                Wall* wall = new Wall(Vector2(startPos.x + x, startPos.y + y));
                walls.push_back(wall);
                actors.PushBack(wall);
            }
            
        }
    }
    // 지뢰 먼저 심기.
    for (int y = 1; y <= totalSizeY - 1; ++y)
    {
        for (int x = 1; x <= totalSizeX - 2; ++x)
        {
            if (Random(1, 10) <= 4)
            {
                Mine* mine = new Mine(Vector2(startPos.x + x, startPos.y + y));
                map.push_back(mine);
                mines.push_back(mine);
                //actors.PushBack(mine);
            }
            else
            {
                Empty* empty = new Empty(Vector2(startPos.x + x, startPos.y + y));
                map.push_back(empty);
                empties.push_back(empty);
                //actors.PushBack(empty);
            }
            
        }
    }

    // MineIndicator 정보 넣기.
    for (int y = 1; y <= totalSizeY - 1; ++y)
    {
        for (int x = 1; x <= totalSizeX - 1; ++x)
        {
            
        }
    }

    std::vector<Vector2> minesList;
    std::vector<Vector2> emptiesList;
    std::vector<Vector2> wallsList;

    for (auto* actor : empties)
    {
        emptiesList.push_back(actor->Position());
    }
    for (auto* actor : mines)
    {
        minesList.push_back(actor->Position());
    }
    for (auto* actor : walls)
    {
        wallsList.push_back(actor->Position());
    }
    // 남은 자리 다 Empty로 채우기.
    
    // 비공개로 덮기(UnopenedCell)


}

void MinesweeperLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);
    if (Game::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
	}
}

void MinesweeperLevel::Draw()
{
    Super::Draw();
    /*for (auto* actor : map)
    {
        actor->Draw();
    }*/
    for (auto& mine : mines)
    {
        mine->Draw();
    }
    // 마지막으로 빈 칸
    for (auto& empty : empties)
    {
        empty->Draw();
    }
}
