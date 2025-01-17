#include "MineIndicator.h"
#include "Game/Game.h"

MineIndicator::MineIndicator(const Vector2& position, int mineCount) /*"·"*/
{
    delete[] image;
    this->position = position;
    if (mineCount == 0)
    {
        viewImage = new char[2] {'O', '\0'};
    }
    else
    {
        viewImage = new char[2] {(char)(mineCount + '0'),'\0'};
    }
    coveredImage = new char[2] {'#', '\0'};
    flagImage = new char[2] {'F', '\0'};
    image = coveredImage;
}

MineIndicator::~MineIndicator()
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

void MineIndicator::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void MineIndicator::Open()
{
    isFlaged = false;
    isOpened = true;
    image = viewImage;
    color = Color::Green;
}

void MineIndicator::OnFlag()
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

bool MineIndicator::GetOpened()
{
    return isOpened;
}

int MineIndicator::GetCount()
{
    return mineCount;
}

