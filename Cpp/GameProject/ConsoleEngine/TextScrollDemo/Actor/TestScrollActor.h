﻿#pragma once

#include "Actor/Actor.h"

class TextScrollActor : public Actor
{
    // 입력 망향 열거형 선언.
    enum class Direction
    {
        None = -1,
        Left = 0,
        Right
    };

	RTTI_DECLARATIONS(TextScrollActor, Actor)
public:
	TextScrollActor(const char* message);
	~TextScrollActor();
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;
private:
    Direction direction = Direction::None;          // 방향 변수.
    bool shouldUpdate = false;                      // 업데이트 여부를 나타내는 함수.
	char* string = nullptr;			                // 화면에 보여줄 문자열 값.
	int length = 0;					                // 문자열 길이.
	int index = 0;					                // 화면에 보여줄 문자열의 시작 인덱스.
	int printWidth = 20;			                // 화면에 보여줄 문자 길이.
    char* temp = nullptr;

	// 딜레이를 위한 변수.
	float elapsedTime = 0.0f;
	float delayTime = 0.08f;
};