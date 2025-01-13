#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vector2.h"

// ������ �⺻ ��ü.
class ENGINE_API Actor : public RTTI
{
	// RTTI ����.
	// ��Ÿ�ӿ� ������ Ÿ���� Ȯ���ϱ� ���� �۾�.
	// dynamic_cast �����ڸ� Ȱ���ؾ� �ϴ� �� ������ ���� Ŀ���� ���� ���.
	RTTI_DECLARATIONS(Actor, RTTI)

	// Level Ŭ������ friend�� ����.
	// private�� ������ �����ϵ���.
	friend class Level;

public:
	Actor();
	virtual ~Actor();

	// ���� ó�� �Լ�.
	virtual void Update(float deltaTime);
	virtual void Draw();

	// Getter/Setter.
	virtual void SetPosition(const Vector2& newPosition);
	inline Vector2 Position() const;

	bool IsActive() const { return isActive; }
	inline void SetActive(bool active) { isActive = active; }
	inline void Destory() { isExpired = true; }

protected:
	// ID(�ؽ�) �Ǵ� �̸� ��.

	Vector2 position;					// ������ ��ġ.
	bool isActive;						// Ȱ��ȭ ���������� ��Ÿ���� ����
	bool isExpired;						// ������ ���� ��û�� �ƴ��� ���θ� ��Ÿ���� ����
};

