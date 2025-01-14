﻿#pragma once
#include <Level/Level.h>
#include <Windows.h>
#include <vector>

// 메뉴 아이템.
struct MenuItem
{
    using OnSelected = void(*)();       // 이벤트 선언.
    MenuItem(const char* text, OnSelected onSelected)
        : onSelected(onSelected)
    {
        size_t length = strlen(text) + 1;
        this->text = new char[length];
        strcpy_s(this->text, length, text);
    }
    ~MenuItem()
    {
        delete[] text;
        text = nullptr;
    }
    char* text;                         // 메뉴에서 보여줄 텍스트.
    OnSelected onSelected;              // 선택했을 때 실행할 함수를 저장하는 포인터.

};

class MenuLevel : public Level
{
    RTTI_DECLARATIONS(MenuLevel, Level)
public:
    MenuLevel();
    ~MenuLevel();
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    // 현재 선택된 메뉴 번호(인덱스).
    int currentSelectedIndex = 0;
    // 선택된 메뉴의 색상.
    int selectedColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    // 선택되지 않은 메뉴의 색상.
    int unselectedColor = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    // 메뉴 저장소.
    std::vector<MenuItem*> items;
    // 아이템 개수.
    int itemCount = 0;
};
