#pragma once

#include "Actor/Actor.h"

class TextScrollActor : public Actor
{
	RTTI_DECLARATIONS(TextScrollActor, Actor)
public:
	TextScrollActor(const char* message);
	~TextScrollActor();
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;
private:
	char* string = nullptr;			// ȭ�鿡 ������ ���ڿ� ��.
	int length = 0;					// ���ڿ� ����.
	int index = 0;					// ȭ�鿡 ������ ���ڿ��� ���� �ε���.
	int printWidth = 20;			// ȭ�鿡 ������ ���� ����.

	// �����̸� ���� ����.
	float elapsedTime = 0.0f;
	float delayTime = 0.08f;
};