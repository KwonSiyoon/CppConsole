#pragma once
#include <Actor/DrawableActor.h>

class PlayerBullet : public DrawableActor
{
    RTTI_DECLARATIONS(PlayerBullet, DrawableActor)

public:
    PlayerBullet(const Vector2& position);          // 탄약은 생성할 때 위치를 전달 받아야 함.
    ~PlayerBullet();
    virtual void Update(float deltaTime) override;

private:
    // 이동 관련 변수.
    float speed = 40.0f;             // 이동 속력 (단위 : 칸/초).
    // y위치.
    float yPosition = 0.0f;
};