#include "PreCompiledHeader.h"
#include "Engine.h"
#include <Windows.h>
#include <iostream>
#include "Level/Level.h"

// 스태틱 변수 초기화.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	instance = this;									// 싱글톤 객체 설정.
}

Engine::~Engine()
{
	// 메인 레벨 메모리 해제.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
}

void Engine::Run()
{
	// timeGetTime 함수는 밀리세컨드(1/1000초) 단위.
	//unsigned long currentTime = timeGetTime();					// 시작 타임 스탬프 저장.
	//unsigned long previousTime = 0;

	// CPU 시계 사용.
	// 시스템 시계 -> 고해상도 카운터. 메인보드에 시계가 있음.(10000000)
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	
	
	LARGE_INTEGER time;									// 시작시간 및 이전시간을 위한 변수.
	QueryPerformanceCounter(&time);

	//__int64 currentTime = time.QuadPart;
	int64_t currentTime = time.QuadPart;
	//__int64 previousTime = 0;
	int64_t previousTime = 0;

	float targetFrameRate = 60.01f;								// 프레임 제한.

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

		//Sleep(20);
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// 기존 레벨이 있다면 삭제 후 교체.

	// 메인 레벨 설정.
	mainLevel = newLevel;
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

Engine& Engine::Get()												// 싱글턴 객체 반환 함수.
{
	return *instance;
}

void Engine::ProcessInput()
{
	for (int i = 0; i < 255; ++i)
	{
		keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
		/*
		4가지 결과가 나온다.
		1. 이전에 누른 적이 없고 호출 시점에서 안눌린 상태 = 0x0000
		x0000 & 0x8000 = 0이 반환 -> FALSE

		2. 이전에 누른 적이 없고 호출 시점에서 눌린 상태 = 0x8000
		x8000 & 0x8000 = 0x8000이 반환 -> 0이 아니므로 -> TRUE

		3. 이전에 누른 적이 있고 호출 시점에서 눌린 상태 = 0x8001
		x8001 & 0x8000 = 0x8000이 반환 -> 0이 아니므로 -> TRUE

		4. 이전에 누른 적이 있고 호출 시점에서 안눌린 상태 = 0x0001
		x0001 & 0x8000 = 0이 반환 -> FALSE

		그러므로 안눌리면 FALSE 눌리면 TRUE가 반환되어 조건문을 통과하게 된다.
		*/
	}
}

void Engine::Update(float deltaTime)
{
	//if (GetKeyDown(VK_ESCAPE))										// ESC키로 게임 종료.
	//{
	//	QuitGame();
	//}
	if (mainLevel != nullptr)										// 레벨 업데이트.
	{
		mainLevel->Update(deltaTime);
	}

	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Draw()
{
	if (mainLevel != nullptr)										// 레벨 그리기.
	{
		mainLevel->Draw();
	}
}

void Engine::SavePreviouseKeyStates()
{
	for (int i = 0; i < 255; ++i)
	{
		keyState[i].wasKeyDown = keyState[i].isKeyDown;
	}
}
