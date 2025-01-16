#include "UnopenedCell.h"

UnopenedCell::UnopenedCell(const Vector2& position)
    : DrawableActor("☐")
{
    this->position = position;
}

void UnopenedCell::IsOpened()
{
    isOpened = true;
}
