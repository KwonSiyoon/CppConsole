#pragma once

#include "Level/Level.h"

class DemoLevel : public Level
{
	// RTTI 정의.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel();
    virtual ~DemoLevel();

    // 루프 처리 함수.
    virtual void Update(float deltaTime) override;
    //virtual void Draw() override;

private:
    void MakeAStarRoad();
    void ResetRoad();
    void MovePlayerAlongRoad();

private:
    bool playMove = false;
    int idx = 0;
    Actor* startActor = nullptr;
    Actor* endActor = nullptr;
    class Player* player = nullptr;
    class Timer* timer = nullptr;
    std::vector<Actor*> actorsInRoad;
    std::vector<class Road*> roadList;
};