#pragma once

#include "Level/Level.h"
#include "Container/List.h"

struct MenuItem
{
	using OnSelected = void (*)();

	MenuItem(const char* text, OnSelected onSelected)
	{
		size_t length = strlen(text);
		menuText = new char[length + 1];
		strcpy_s(menuText, length + 1, text);

		this->onSelected = onSelected;
	}

	~MenuItem()
	{
		delete[] menuText;
	}

	char* menuText;
	OnSelected onSelected;
};

class MenuLevel : public Level
{
	RTTI_DECLARATIONS(MenuLevel, Level)

public:
	MenuLevel();
	~MenuLevel();

    void SetCursorPosition(int x, int y);
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;
    // 콘솔 색상 설정 함수.
    inline void SetColor(Color color);


private:
	int currentIndex = 0;
	Color selectedColor = Color::Green;
	Color unselectedColor = Color::White;

	List<MenuItem*> menuItems;
	int length = 0;
};