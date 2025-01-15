#include "Box.h"

Box::Box(const Vector2& position)
    : DrawableActor("b")
{
    this->position = position;      // 위치 설정.
    color = Color::White;           // 색상 설정.
}

void Box::Update(float deltaTime)
{
}
