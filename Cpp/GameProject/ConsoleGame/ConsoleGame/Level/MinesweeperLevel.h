#pragma once
#include "Level/Level.h"
#include <vector>
#include "Math/Vector2.h"


class DrawableActor;
class Mine;
class MineIndicator;
class Empty;
class Wall;
class UnopenedCell;
class MinesweeperLevel : public Level
{
    RTTI_DECLARATIONS(MinesweeperLevel, Level)
public:
    MinesweeperLevel(int xSize = 0, int ySize = 0);
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    std::vector<DrawableActor*> map;
    std::vector<Mine*> mines;
    std::vector<MineIndicator*> indicators;
    std::vector<Empty*> empties;
    std::vector<Wall*> walls;
    std::vector<UnopenedCell*> UnopenedCells;
    bool isGameClear = false;
    Vector2 gameSize = Vector2(10, 10);
};