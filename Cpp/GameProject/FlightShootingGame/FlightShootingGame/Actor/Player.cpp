#include "Player.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"
#include "Actor/PlayerBullet.h"

Player::Player(const char* image)
	: Super(image)
{
    //SetPosition(Vector2(0, 20));
    position = Vector2(0, Engine::Get().ScreenSize().y - 1);
}

void Player::Update(float deltaTime)
{
	// 부모 함수 호출.
	Super::Update(deltaTime);

    // 탄약 발사.
    if (Engine::Get().GetKey(VK_SPACE))
    {
        Vector2 bulletPosition(position.x + width / 2, position.y);
        Engine::Get().AddActor(new PlayerBullet(bulletPosition));
    }


	// 키 입력 처리.
	if (Engine::Get().GetKey(VK_LEFT))
	{
		// 새 위치 계산.
		Vector2 newPosition = position;
		--newPosition.x;
		if (newPosition.x < 0)
		{
			newPosition.x = 0;
		}
		SetPosition(newPosition);
	}
	if (Engine::Get().GetKey(VK_RIGHT))
	{
		// 새 위치 계산.
		Vector2 newPosition = position;
		++newPosition.x;
		if (newPosition.x > Engine::Get().ScreenSize().x - width)
		{
			newPosition.x = Engine::Get().ScreenSize().x - width;
		}
		SetPosition(newPosition);
	}
	//if (Engine::Get().GetKey(VK_DOWN))
	//{
	//	// 새 위치 계산.
	//	Vector2 newPosition = position;
	//	++newPosition.y;
	//	if (newPosition.y > 25)
	//	{
	//		newPosition.y = 25;
	//	}
	//	SetPosition(newPosition);
	//	
	//}
	//if (Engine::Get().GetKey(VK_UP))
	//{
	//	// 새 위치 계산.
	//	Vector2 newPosition = position;
	//	--newPosition.y;
	//	if (newPosition.y < 0)
	//	{
	//		newPosition.y = 0;
	//	}
	//	SetPosition(newPosition);
	//}
}
