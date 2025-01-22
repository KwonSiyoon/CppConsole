#include "MineIndicator.h"
#include "Game/Game.h"

MineIndicator::MineIndicator(const Vector2& position, int mineCount, std::function<void()> decreaseCount) /*"·"*/
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
    
    const char* cover = "○";
    auto length = strlen(cover) + 1;
    coveredImage = new char[length];
    strcpy_s(coveredImage, length, cover);

    flagImage = new char[2] {'F', '\0'};
    image = coveredImage;
    this->decreaseCount = decreaseCount;
}

MineIndicator::~MineIndicator()
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

void MineIndicator::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

void MineIndicator::Open()
{
    isFlaged = false;
    isOpened = true;
    image = viewImage;
    color = Color::Ten; // 밝은 초록.
    if(decreaseCount) decreaseCount();
}

void MineIndicator::OnFlag()
{
    if (isOpened) return;
    isFlaged = !isFlaged;
    if (isFlaged)
    {
        image = flagImage;
        color = Color::Three; // 옅은 파랑.
    }
    else
    {
        image = coveredImage;
        color = Color::White;
    }
}

bool MineIndicator::GetFlag()
{
    return isFlaged;
}

bool MineIndicator::GetOpened()
{
    return isOpened;
}

int MineIndicator::GetCount()
{
    return mineCount;
}

