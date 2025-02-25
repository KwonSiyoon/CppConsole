#include "RedBlackLevel.h"

#include "Algorithm/RedBlackTree.h"
#include "Engine/Engine.h"


RedBlackLevel::RedBlackLevel()
{
}

void RedBlackLevel::Update(float deltaTime)
{
    if (Engine::Get().GetKeyDown(VK_RETURN))
    {

    }
    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }
}
