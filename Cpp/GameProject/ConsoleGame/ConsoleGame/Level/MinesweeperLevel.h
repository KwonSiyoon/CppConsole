#pragma once
#include "Level/Level.h"
#include <vector>
#include "Math/Vector2.h"


class DrawableActor;
class Mine;
class MineIndicator;
class Wall;
class MinesweeperLevel : public Level
{
    RTTI_DECLARATIONS(MinesweeperLevel, Level)
public:
    MinesweeperLevel(int xSize = 0, int ySize = 0, const Vector2& startPos = Vector2(2,2));
    virtual ~MinesweeperLevel() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    void DecreaseMineCount();;
    void DecreaseIndicatorCount();
    void GameClear();
    void Retry();
private:
    void Initialize(const Vector2& gameSize, const Vector2& startPos);
    void MouseEvent();
    void GameOver();
    int CheckSurroundMines(int**& array, int x, int y);
    void OpenSurroundingZeros(int x, int y);
    MineIndicator* GetIndicatorAt(int x, int y);  // 특정 위치의 indicator를 찾는 함수
private:
    std::vector<DrawableActor*> map;
    std::vector<Mine*> mines;
    std::vector<MineIndicator*> indicators;
    int** mapArray{};
    bool isGameClear = false;
    Vector2 gameSize = Vector2(10, 10);
    Vector2 startPos = Vector2(2, 2);
    int mineCounts = 0;
    int indicatorCounts = 0;
    bool isGameOver = false;
};