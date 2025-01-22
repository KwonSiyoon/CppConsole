#include "Mine.h"
#include "Game/Game.h"

Mine::Mine(const Vector2& position, std::function<void()> callback)
{
    delete[] image;
    this->position = position;

    const char* cover = "○";
    auto length = strlen(cover) + 1;
    coveredImage = new char[length];
    strcpy_s(coveredImage, length, cover);

    viewImage = new char[2] {'@', '\0'};
    flagImage = new char[2] {'F', '\0'};
    image = coveredImage;
    this->decreaseCount = callback;
}

Mine::~Mine()
{
    image = nullptr;
    delete[] coveredImage;
    delete[] viewImage;
    delete[] flagImage;
    /*if (isFlaged)
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
    }*/
}

void Mine::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void Mine::Open()
{
    if (isOpened) return;
    isOpened = true;
    isFlaged = false;
    image = viewImage;
    color = Color::Red;
    if (decreaseCount) decreaseCount();
}

void Mine::OnFlag()
{
    if (isOpened) return;
    isFlaged = !isFlaged;
    if (isFlaged)
    {
        image = flagImage;
        color = Color::Three;
    }
    else
    {
        image = coveredImage;
        color = Color::White;
    }
}

bool Mine::GetFlag()
{
    return isFlaged;
}

bool Mine::GetOpen()
{
    return isOpened;
}
