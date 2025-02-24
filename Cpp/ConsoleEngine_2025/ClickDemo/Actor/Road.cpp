#include "Road.h"

Road::Road(const Vector2& position)
    : DrawableActor("+")
{
    color = Color::White;
    this->position = position;
}

void Road::Update(float deltaTime)
{
}
