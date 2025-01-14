#include "PreCompiledHeader.h"
#include "Engine.h"
#include <Windows.h>
#include <iostream>
#include "Level/Level.h"
#include "Actor/Actor.h"
#include <time.h>
// 스태틱 변수 초기화.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(80,25)
{
    // 랜덤 시드 설정.
    srand((unsigned int)time(nullptr));

	instance = this;									// 싱글톤 객체 설정.
	SetTargetFrameRate(60.0f);							// 기본 타겟 프레임 속도 설정.
    // 1. 버퍼 크기 할당.
    emptyStringBuffer = new char[(screenSize.x + 1) * screenSize.y + 1]; // 화면 지울 때 사용할 버퍼 초기화.
    
    // 버퍼 덮어쓰기.
    memset(emptyStringBuffer, ' ', (screenSize.x + 1) * screenSize.y + 1);

    // 2. 값 할당.
    for (int y = 0; y < screenSize.y; ++y)
    {
        //for (int x = 0; x < screenSize.x; ++x)
        //{
        //    // 인덱스 계산 잘하기.
        //    emptyStringBuffer[(y * (screenSize.x + 1)) + x] = ' ';
        //}
        // 각 줄 끝에 개행 문자 추가.
        emptyStringBuffer[(y * (screenSize.x + 1)) + screenSize.x] = '\n';
    }

    // 마지막에 널 문자 추가.
    emptyStringBuffer[(screenSize.x + 1) * screenSize.y] = '\0';

    // 디버깅.
#if _DEBUG
    char buffer[2048];
    strcpy_s(buffer, 2048, emptyStringBuffer);
#endif
}

Engine::~Engine()
{
	// 메인 레벨 메모리 해제.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
    // 클리어 버퍼 삭제.
    delete[] emptyStringBuffer;
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
	//__int64 previousTime = 0;
	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	//float targetFrameRate = 60.01f;								// 프레임 제한.

	//float targetOneFrameTime = 1.0f / targetFrameRate;			// 한 프레임 시간 계산.

	

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
		
		//float targetOneFrameTime = 1.0f / targetFrameRate;			// 한 프레임 시간 계산.

		if (deltaTime >= targetOneFrameTime)					// 프레임 확인.
		{

			ProcessInput();										// 입력 처리 ( 현재 키의 눌림 상태 확인)
			
			// 업데이트 가능한 상태에서만 프레임 업데이트 처리.
			if (shouldUpdata)
			{
				Update(deltaTime);
				Draw();
			}

			SavePreviouseKeyStates();							// 키 상태 저장.

			previousTime = currentTime;							// 이전 프레임 시간 저장.

			// 액터 정리 (삭제 요청된 액터들 정리).
			if (mainLevel)
			{
                mainLevel->ProcessAddedAndDestroyedActor();
			}

			// 프레임 활성화.
			shouldUpdata = true;
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

void Engine::AddActor(Actor* newActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	shouldUpdata = false;
	// 레벨에 액터 추가.
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}
	shouldUpdata = false;
	targetActor->Destory();
}

void Engine::SetCursorType(CursorType cursorType)
{
	// 1. 커서 속성 구조체 설정.
	CONSOLE_CURSOR_INFO info = {};

	// 타입 별로 구조체 값 설정.
	switch (cursorType)
	{
	case CursorType::NoCursor:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case CursorType::SolidCursor:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case CursorType::NormalCursor:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	default:
		break;
	}

	// 2. 설정.
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
	SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)						// 콘솔에 글자의 위치를 정해주는 함수.
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { static_cast<short>(x), static_cast<short>(y) };
	SetConsoleCursorPosition(handle, coord);
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	this->targetFrameRate = targetFrameRate;
	targetOneFrameTime = 1.0f / targetFrameRate;
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

void Engine::Clear()
{
	// 화면의 (0,0)으로 이동.
	SetCursorPosition(0, 0);
	// 화면 지우기.
    std::cout << emptyStringBuffer;
    
    /*int height = 25;
	for (int i = 0; i < height; ++i)
	{
		Log("                              \n");
	}*/

	// 화면의 (0,0)으로 이동.
	SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	Clear();														// 화면 지우기.

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
