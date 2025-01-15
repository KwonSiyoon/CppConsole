#include "Player.h"
#include "Engine/Engine.h"
#include "Level/GameLevel.h"

Player::Player(const Vector2& position, GameLevel* level)
    : DrawableActor("P"), refLevel(level)
{
    this->position = position;
    color = Color::Purple;
}

void Player::Update(float deltaTime)
{
    Super::Update(deltaTime);

    // ESC 종료.
    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }
    // 상하좌우.
    if (Engine::Get().GetKeyDown(VK_LEFT))
    {
        if (refLevel->CanPlayerMove(Vector2(position.x - 1, position.y)))
        {
            position.x -= 1;
        }
        //position.x = position.x < 0 ? 0 : position.x;
    }
    if (Engine::Get().GetKeyDown(VK_RIGHT))
    {
        if (refLevel->CanPlayerMove(Vector2(position.x + 1, position.y)))
        {
            position.x += 1;
        }
        /*position.x += 1;
        position.x = position.x >= Engine::Get().ScreenSize().x ? Engine::Get().ScreenSize().x : position.x;*/
    }
    if (Engine::Get().GetKeyDown(VK_UP))
    {
        if (refLevel->CanPlayerMove(Vector2(position.x, position.y-1)))
        {
            position.y -= 1;
        }
        /*position.y -= 1;
        position.y = position.y < 0? 0 : position.y;*/
    }
    if (Engine::Get().GetKeyDown(VK_DOWN))
    {
        if (refLevel->CanPlayerMove(Vector2(position.x, position.y + 1)))
        {
            position.y += 1;
        }
        /*position.y += 1;
        position.y = position.y >= Engine::Get().ScreenSize().y ? Engine::Get().ScreenSize().y : position.y;*/
    }
}
