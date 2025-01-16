#pragma once
#include "Actor/DrawableActor.h"

class Mine : public DrawableActor
{
    RTTI_DECLARATIONS(Mine, DrawableActor)
public:
    Mine(const Vector2& position);
private:


};