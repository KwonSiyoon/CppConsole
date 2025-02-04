#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(float x, float y)
    : x(x), y(y)
{
}

float Rectangle::GetArea()
{
    return x * y;
}

float Rectangle::GetSize()
{
    return 2.0f * (x + y);
}
