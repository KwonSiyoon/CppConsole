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
	char* string = nullptr;			// 화면에 보여줄 문자열 값.
	int length = 0;					// 문자열 길이.
	int index = 0;					// 화면에 보여줄 문자열의 시작 인덱스.
	int printWidth = 20;			// 화면에 보여줄 문자 길이.

	// 딜레이를 위한 변수.
	float elapsedTime = 0.0f;
	float delayTime = 0.08f;
};