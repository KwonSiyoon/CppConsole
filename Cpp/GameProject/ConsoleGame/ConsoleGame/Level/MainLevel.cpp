#include "MainLevel.h"
#include "Game/Game.h"
#include "MinesweeperLevel.h"

MainLevel::MainLevel()
{
    Engine::Get().SetCursorType(CursorType::NoCursor);
    gameSizes.push_back(new GameSize("Easy", Vector2(15, 8)));
    gameSizes.push_back(new GameSize("Normal", Vector2(30, 15)));
    gameSizes.push_back(new GameSize("Hard", Vector2(50, 20)));

    length = (int)gameSizes.size();
}

MainLevel::~MainLevel()
{
    for (auto* item : gameSizes)
    {
        delete item;
    }
}

void MainLevel::LoadMinesweeperLevel(const Vector2& gameSize)
{
    system("cls");
    Game::Get().ClearAndLoadLevel(new MinesweeperLevel(gameSize.x, gameSize.y));
}

void MainLevel::Update(float deltaTime)
{
    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMenu();
    }
    if (Game::Get().GetKeyDown(VK_LEFT))
    {
        currentIndex = (currentIndex - 1 + length) % length;
    }
    if (Game::Get().GetKeyDown(VK_RIGHT))
    {
        currentIndex = (currentIndex + 1) % length;
    }
    if (Game::Get().GetKeyDown(VK_RETURN))
    {
        LoadMinesweeperLevel(gameSizes[currentIndex]->size);
    }
}

void MainLevel::Draw()
{
    Super::Draw();
    SetColor(Color::White);
    Engine::Get().SetCursorPosition(0, 0);
    std::cout << "☆★☆★☆★☆★☆★ 지뢰 찾기 ☆★☆★☆★☆★☆★\n\n    난이도를 선택하세요.";

    Engine::Get().SetCursorPosition(0, 5);
    for (int i = 0; i < length; ++i)
    {
        SetColor(i == currentIndex ? selectedColor : unselectedColor);
        Log("   %s ", gameSizes[i]->text);
    }
}
