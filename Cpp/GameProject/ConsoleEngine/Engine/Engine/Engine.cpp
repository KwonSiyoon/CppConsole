#include "Engine.h"
#include <Windows.h>
#include <iostream>

Engine::Engine()
	: quit(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	//unsigned long currentTime = timeGetTime();					// 시작 타임 스탬프 저장.
	//unsigned long previousTime = 0;


	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	
	LARGE_INTEGER time;									// 시작시간 및 이전시간을 위한 변수.
	QueryPerformanceCounter(&time);

	//__int64 currentTime = time.QuadPart;
	int64_t currentTime = time.QuadPart;
	//__int64 previousTime = 0;
	int64_t previousTime = 0;

	float targetFrameRate = 1000.01f;								// 프레임 제한.

	float targetOneFrameTime = 1.0f / targetFrameRate;			// 한 프레임 시간 계산.

	

	while (true)												// Game-Loop
	{
		if (quit)												// 종료 조건.
		{
			break;
		}

		//currentTime = timeGetTime();							// 현재 프레임 시간 저장.
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);




		if (deltaTime >= targetOneFrameTime)					// 프레임 확인.
		{

			ProcessInput();										// 입력 처리 ( 현재 키의 눌림 상태 확인)
			Update(deltaTime);
			Draw();

			SavePreviouseKeyStates();							// 키 상태 저장.

			previousTime = currentTime;							// 이전 프레임 시간 저장.
		}

		Sleep(20);
	}
}

bool Engine::GetKey(int key)
{
	return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
	return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	quit = true;													// 종료 플래그 설정.
}

void Engine::ProcessInput()
{
	for (int i = 0; i < 255; ++i)
	{
		keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	if (GetKeyDown(VK_ESCAPE))										// ESC키로 게임 종료.
	{
		QuitGame();
	}

	std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Draw()
{
}

void Engine::SavePreviouseKeyStates()
{
	for (int i = 0; i < 255; ++i)
	{
		keyState[i].wasKeyDown = keyState[i].isKeyDown;
	}
}
