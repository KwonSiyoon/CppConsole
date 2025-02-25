#pragma once

#include "Actor/DrawableActor.h"
#include <vector>

class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public:
	Player();
};