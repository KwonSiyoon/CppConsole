#pragma once

#include "Actor/DrawableActor.h"

class End : public DrawableActor
{
    RTTI_DECLARATIONS(End, DrawableActor)
public:
    End();

    virtual void Update(float deltaTime) override;

};