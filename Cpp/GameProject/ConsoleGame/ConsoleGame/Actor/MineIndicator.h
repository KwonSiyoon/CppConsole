#pragma once
#include "Actor/DrawableActor.h"

class MineIndicator : public DrawableActor
{
    RTTI_DECLARATIONS(MineIndicator, DrawableActor)
public:
    MineIndicator(const Vector2& position);
protected:
    int mineCount = 0;

};