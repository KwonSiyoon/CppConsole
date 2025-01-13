﻿#include "TestScrollActor.h"
#include "Engine/Engine.h"
#include <Windows.h>

TextScrollActor::TextScrollActor(const char* message)
{
	// 문자열 길이 구하기.
	length = (int)strlen(message);

	// 문자열 복사.
	string = new char[length + 1];
	strcpy_s(string, length + 1, message);
    temp = new char[printWidth + 1];

	// 커서 감추기.
	Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
	delete[] string;
    delete[] temp;
}

void TextScrollActor::Update(float deltaTime)
{
	// ESC 종료.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
    // 좌우 방향키 입력 처리.
    if (Engine::Get().GetKey(VK_LEFT))
    {
        // 방향 설정.
        direction = Direction::Left;
        shouldUpdate = true;
    }
    if (Engine::Get().GetKey(VK_RIGHT))
    {
        // 방향 설정.
        direction = Direction::Right;
        shouldUpdate = true;
    }
    // 방향키가 안눌렸는지 확인.
    if (!Engine::Get().GetKey(VK_LEFT) && !Engine::Get().GetKey(VK_RIGHT))
    {
        shouldUpdate = false;
    }

	// 딜레이 계산.
	elapsedTime += deltaTime;
	// 시간이 모두 경과했는지 확인
	if (elapsedTime < delayTime)
	{
		return;
	}
	// 시간이 경과 했으면 다음 계산을 위해 초기화.
	elapsedTime = 0.0f;

    if (shouldUpdate)
    {
        if (direction == Direction::Right)
        {
            // 화면에 그릴 문자열의 시작 인덱스 업데이트.
            index = (index + 1) % length;
        }
        else if (direction == Direction::Left)
        {
            // 화면에 그릴 문자열의 시작 인덱스 업데이트.
            index = (index - 1 + length) % length;
        }
    }

	
}

void TextScrollActor::Draw()
{
	// 임시 문자열 버퍼.
	//char* temp = new char[printWidth + 1];		// null 문자열이 와야하기 때문에 printWidth+1

	int tempIndex = index;

	for (int i = 0; i < printWidth; ++i)
	{
		temp[i] = string[tempIndex];
		tempIndex = (tempIndex + 1) % length;
	}
	temp[printWidth] = '\0';					// null문자
	Log(temp);
	//delete[] temp;
	Engine::Get().SetCursorPosition(0, 0);
	//Sleep(50);
}
