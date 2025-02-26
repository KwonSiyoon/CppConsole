#pragma once

#include "Level/Level.h"
#include "Container/List.h"


class MenuLevel : public Level
{
	RTTI_DECLARATIONS(MenuLevel, Level)

public:
	MenuLevel();
	~MenuLevel();

	virtual void Update(float deltaTime) override;

private:
	int currentIndex = 0;
	Color selectedColor = Color::Green;
	Color unselectedColor = Color::White;

	List<class MenuActor*> menuItems;
	int length = 0;
};