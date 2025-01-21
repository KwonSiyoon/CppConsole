#include "Wall.h"

Wall::Wall(const Vector2& position, const char* img)
    : DrawableActor("W")
{
    if (img)
    {
        delete[] image;
        auto length = strlen(img) + 1;
        this->image = new char[length];
        strcpy_s(this->image, length, img);
    }
    this->position = position;
    color = Color::Purple;
}
