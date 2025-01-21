#pragma once
#include "Level/Level.h"
#include "vector"
#include "Math/Vector2.h"

struct GameSize
{
    GameSize(const char* text, const Vector2& size)
        : size(size)
    {
        size_t length = strlen(text);
        this->text = new char[length + 1];
        strcpy_s(this->text, length + 1, text);
    }
    ~GameSize()
    {
        delete[] text;
    }
    Vector2 size;
    char* text;
};


class MainLevel : public Level
{
    RTTI_DECLARATIONS(MainLevel, Level)

public:
    MainLevel();
    ~MainLevel();
    
    void LoadMinesweeperLevel(const Vector2& gameSize);
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    int currentIndex = 0;
    Color selectedColor = Color::Green;
    Color unselectedColor = Color::White;

    std::vector<GameSize*> gameSizes;
    int length = 0;
};