﻿#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"

DrawableActor::DrawableActor(const char* image)
    : Actor()/*, image(image)*/
{
    // 전달 받은 문자열 복사.
    auto length = strlen(image) + 1;
    this->image = new char[length];
    strcpy_s(this->image, length, image);
}
DrawableActor::~DrawableActor()
{
    delete[] image;
}

void DrawableActor::Draw()
{
	Super::Draw();			// 부모를 Super로 가리킴(유니티에서 Base 역할)

	// 그리기.
	// 1단계: 콘솔 좌표 옮기기.
	Engine::Get().SetCursorPosition(position);
	// 2단계: 그리기(콘솔 출력).
	Log("%s", image);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	// 이전의 위치를 먼저 지우기.
	Engine::Get().SetCursorPosition(position);
	Log(" ");

	// 위치를 새로 옮기기.
	Super::SetPosition(newPosition);
}
