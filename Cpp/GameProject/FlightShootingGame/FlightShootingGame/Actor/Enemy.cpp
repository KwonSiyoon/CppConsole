#include "Enemy.h"
#include "Engine/Engine.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image, int yPosition)
    : DrawableActor(image)
{
    // 랜덤으로 이동할 방향 선택.
    int random = Random(1, 10);
    if (random % 2 == 0)
    {
        // 짝수인 경우에는 왼쪽으로 이동.
        direction = Direction::Left;

        // 처음 x좌표를 화면 끝으로 설정.
        xPosition = (float)(Engine::Get().ScreenSize().x - width);
    }
    else
    {
        // 홀수인 경우에는 오른쪽으로 이동.
        direction = Direction::Right;

        // 처음 x좌표를 0으로 설정.
        xPosition = 0;
    }

    // 시작 위치 설정.
    this->position = Vector2((int)xPosition, yPosition);
}

void Enemy::Update(float deltaTime)
{
    Super::Update(deltaTime);
    float factor = direction == Direction::Left ? -1.0f : 1.0f;
    xPosition += speed *factor* deltaTime;
    position.x = (int)xPosition;

    if (xPosition < 0.0f || xPosition > Engine::Get().ScreenSize().x - width)
    {
        Destroy();
        return;
    }
    static float elapsedTime = 0.0f;
    static float fireInterval = RandomPercent(1.0f, 2.0f);

    // 타이머 업데이트
    elapsedTime += deltaTime;

    // 타이머 처리.
    if (elapsedTime < fireInterval)
    {
        return;
    }
    // 타이머 초기화.
    elapsedTime = 0.0f;
    fireInterval = RandomPercent(1.0f, 2.0f);

    // 탄약 생성.
    Engine::Get().AddActor(new EnemyBullet(Vector2(position.x + width / 2, position.y)));


    ////if (direction == Direction::Right)
    //if(factor >0)
    //{
    //    //xPosition += speed * deltaTime;
    //    if (xPosition > Engine::Get().ScreenSize().x - width)
    //    {
    //        Destory();
    //        return;
    //    }
    //}
    ////else if (direction == Direction::Left)
    //else if (factor < 0)
    //{
    //    //xPosition -= speed * deltaTime;
    //    if (xPosition < 0)
    //    {
    //        Destory();
    //        return;
    //    }
    //    
    //}
    ////position.x = (int)xPosition;
    //
    
}
