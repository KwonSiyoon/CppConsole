#pragma once

#include "Core.h"
#include "RTTI.h"

// ������ �⺻ ��ü.
class ENGINE_API Actor : public RTTI
{
	// RTTI ����.
	// ��Ÿ�ӿ� ������ Ÿ���� Ȯ���ϱ� ���� �۾�.
	// dynamic_cast �����ڸ� Ȱ���ؾ� �ϴ� �� ������ ���� Ŀ���� ���� ���.
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor();
	virtual ~Actor();

	// ���� ó�� �Լ�.
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	// ID(�ؽ�) �Ǵ� �̸� ��.

	bool isActive;						// Ȱ��ȭ ���������� ��Ÿ���� ����
	bool isExpired;						// ������ ���� ��û�� �ƴ��� ���θ� ��Ÿ���� ����
};

