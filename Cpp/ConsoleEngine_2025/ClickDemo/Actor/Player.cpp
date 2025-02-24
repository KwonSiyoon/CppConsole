#include "Player.h"
#include "Engine/Engine.h"

Player::Player()
	: DrawableActor("P")
{
	color = Color::Blue;
	position = Vector2(5, 5);
}

void Player::Update(float deltaTime)
{
	
}