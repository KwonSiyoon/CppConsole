#pragma once
#include <Level/Level.h>
#include <Math/Vector2.h>

// 소코반 게임 레벨.
class DrawableActor;
class Player;
class Box;
class Target;
class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)
public:
    GameLevel();
    virtual void Draw() override;                           // 레벨의 그리기 함수.
    virtual void Update(float deltaTime) override;
    bool CanPlayerMove(const Vector2& position);            // 플레이어가 이동이 가능한지 확인하는 함수.
private:
    bool CheckIsGameClear();                                // 박스를 옮긴 뒤 게임을 클리어했는지 확인하는 함수.
private:
    List<DrawableActor*> map;       // 벽/땅 액터 배열.
    List<Box*> boxes;               // 박스 액터.
    List<Target*> targets;          // 타겟 액터.
    Player* player = nullptr;       // 플레이어 액터.
    bool isGameClear = false;       // 게임 클리어 변수.
};