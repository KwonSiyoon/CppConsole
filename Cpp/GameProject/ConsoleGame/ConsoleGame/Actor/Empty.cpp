#include "Empty.h"

Empty::Empty(const Vector2& position) /*"·"*/
    : DrawableActor()
{
    this->position = position;
    if (mineCount == 0)
    {
        *image = '2';
    }
    else
    {
        *image = mineCount + '0';
    }
}
