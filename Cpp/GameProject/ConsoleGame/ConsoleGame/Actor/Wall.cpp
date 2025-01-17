#include "Wall.h"

Wall::Wall(const Vector2& position)
    : DrawableActor("W")/*"█"안됨.*/
{
    this->position = position;
    color = Color::Red;
}
