#pragma once
#include "Actor/DrawableActor.h"

class UnopenedCell : public DrawableActor
{
    RTTI_DECLARATIONS(UnopenedCell, DrawableActor)
public:
    UnopenedCell(const Vector2& position);
    void IsOpened();
private:
    bool isOpened = false;

};