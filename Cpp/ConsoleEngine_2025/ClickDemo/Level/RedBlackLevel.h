#pragma once
#include "Level/Level.h"

class RedBlackLevel : public Level
{
    RTTI_DECLARATIONS(RedBlackLevel, Level)
public:
    RedBlackLevel();

    virtual void Update(float deltaTime) override;

private:


};
