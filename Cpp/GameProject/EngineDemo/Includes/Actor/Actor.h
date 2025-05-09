#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vector2.h"

// 레벨의 기본 물체.
class ENGINE_API Actor : public RTTI
{
	// RTTI 선언.
	// 런타임에 빠르게 타입을 확인하기 위한 작업.
	// dynamic_cast 연산자를 활용해야 하는 데 성능을 위해 커스텀 버전 사용.
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor();
	virtual ~Actor();

	// 루프 처리 함수.
	virtual void Update(float deltaTime);
	virtual void Draw();

	// Getter/Setter.
	virtual void SetPosition(const Vector2& newPosition);
	inline Vector2 Position() const;

protected:
	// ID(해시) 또는 이름 값.

	Vector2 position;					// 액터의 위치.
	bool isActive;						// 활성화 상태인지를 나타내는 변수
	bool isExpired;						// 액터의 제거 요청이 됐는지 여부를 나타내는 변수
};

