#pragma once

#include "Level/Level.h"

class DemoLevel : public Level
{
	// RTTI 정의.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel();

    // 루프 처리 함수.
    virtual void Update(float deltaTime) override;
    //virtual void Draw() override;

private:
    void MakeAStarRoad();
    void ResetRoad();

private:
    Actor* startActor = nullptr;
    Actor* endActor = nullptr;
    std::vector<class Road*> roadList;
};