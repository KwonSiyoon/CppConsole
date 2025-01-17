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
    MinesweeperLevel(int xSize = 0, int ySize = 0);
    virtual ~MinesweeperLevel() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
private:
    void MouseEvent();
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
};