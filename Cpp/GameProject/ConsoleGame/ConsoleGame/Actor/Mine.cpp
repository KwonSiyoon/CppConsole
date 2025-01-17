#include "Mine.h"
#include "Game/Game.h"

Mine::Mine(const Vector2& position)
{
    delete[] image;
    this->position = position;
    coveredImage = new char[2] {'#', '\0'};
    viewImage = new char[2] {'@', '\0'};
    flagImage = new char[2] {'F', '\0'};
    image = coveredImage;
}

Mine::~Mine()
{
    if (isFlaged)
    {
        delete[] coveredImage;
        delete[] viewImage;
        return;
    }
    if (isOpened)
    {
        delete[] coveredImage;
        delete[] flagImage;
    }
    else
    {
        delete[] flagImage;
        delete[] viewImage;
    }
}

void Mine::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void Mine::Open()
{
    isOpened = true;
    isFlaged = false;
    image = viewImage;
    color = Color::Red;
}

void Mine::OnFlag()
{
    if (isOpened) return;
    isFlaged = !isFlaged;
    if (isFlaged)
    {
        image = flagImage;
        color = Color::Blue;
    }
    else
    {
        image = coveredImage;
        color = Color::White;
    }
}
