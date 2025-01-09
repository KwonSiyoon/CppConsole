#include "PreCompiledHeader.h"
#include "Engine.h"
#include <Windows.h>
#include <iostream>
#include "Level/Level.h"
#include "Actor/Actor.h"
// ����ƽ ���� �ʱ�ȭ.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	instance = this;									// �̱��� ��ü ����.
	SetTargetFrameRate(60.0f);							// �⺻ Ÿ�� ������ �ӵ� ����.
}

Engine::~Engine()
{
	// ���� ���� �޸� ����.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
}

void Engine::Run()
{
	// timeGetTime �Լ��� �и�������(1/1000��) ����.
	//unsigned long currentTime = timeGetTime();					// ���� Ÿ�� ������ ����.
	//unsigned long previousTime = 0;

	// CPU �ð� ���.
	// �ý��� �ð� -> ���ػ� ī����. ���κ��忡 �ð谡 ����.(10000000)
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	
	
	LARGE_INTEGER time;									// ���۽ð� �� �����ð��� ���� ����.
	QueryPerformanceCounter(&time);

	//__int64 currentTime = time.QuadPart;
	int64_t currentTime = time.QuadPart;
	//__int64 previousTime = 0;
	int64_t previousTime = 0;

	//float targetFrameRate = 60.01f;								// ������ ����.

	//float targetOneFrameTime = 1.0f / targetFrameRate;			// �� ������ �ð� ���.

	

	while (true)												// Game-Loop
	{
		if (quit)												// ���� ����.
		{
			break;
		}

		//currentTime = timeGetTime();							// ���� ������ �ð� ����.
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);
		
		//float targetOneFrameTime = 1.0f / targetFrameRate;			// �� ������ �ð� ���.

		if (deltaTime >= targetOneFrameTime)					// ������ Ȯ��.
		{

			ProcessInput();										// �Է� ó�� ( ���� Ű�� ���� ���� Ȯ��)
			
			// ������Ʈ ������ ���¿����� ������ ������Ʈ ó��.
			if (shouldUpdata)
			{
				Update(deltaTime);
				Draw();
			}

			SavePreviouseKeyStates();							// Ű ���� ����.

			previousTime = currentTime;							// ���� ������ �ð� ����.

			// ���� ���� (���� ��û�� ���͵� ����.
			if (mainLevel)
			{
				mainLevel->DestroyActor();
			}

			// ������ Ȱ��ȭ.
			shouldUpdata = true;
		}

		//Sleep(20);
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// ���� ������ �ִٸ� ���� �� ��ü.

	// ���� ���� ����.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}

	shouldUpdata = false;
	// ������ ���� �߰�.
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}
	shouldUpdata = false;
	targetActor->Destory();
}

void Engine::SetCursorType(CursorType cursorType)
{
	// 1. Ŀ�� �Ӽ� ����ü ����.
	CONSOLE_CURSOR_INFO info = {};

	// Ÿ�� ���� ����ü �� ����.
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

	// 2. ����.
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
	SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)						// �ֿܼ� ������ ��ġ�� �����ִ� �Լ�.
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
	quit = true;													// ���� �÷��� ����.
}

Engine& Engine::Get()												// �̱��� ��ü ��ȯ �Լ�.
{
	return *instance;
}

void Engine::ProcessInput()
{
	for (int i = 0; i < 255; ++i)
	{
		keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
		/*
		4���� ����� ���´�.
		1. ������ ���� ���� ���� ȣ�� �������� �ȴ��� ���� = 0x0000
		x0000 & 0x8000 = 0�� ��ȯ -> FALSE

		2. ������ ���� ���� ���� ȣ�� �������� ���� ���� = 0x8000
		x8000 & 0x8000 = 0x8000�� ��ȯ -> 0�� �ƴϹǷ� -> TRUE

		3. ������ ���� ���� �ְ� ȣ�� �������� ���� ���� = 0x8001
		x8001 & 0x8000 = 0x8000�� ��ȯ -> 0�� �ƴϹǷ� -> TRUE

		4. ������ ���� ���� �ְ� ȣ�� �������� �ȴ��� ���� = 0x0001
		x0001 & 0x8000 = 0�� ��ȯ -> FALSE

		�׷��Ƿ� �ȴ����� FALSE ������ TRUE�� ��ȯ�Ǿ� ���ǹ��� ����ϰ� �ȴ�.
		*/
	}
}

void Engine::Update(float deltaTime)
{
	//if (GetKeyDown(VK_ESCAPE))										// ESCŰ�� ���� ����.
	//{
	//	QuitGame();
	//}
	if (mainLevel != nullptr)										// ���� ������Ʈ.
	{
		mainLevel->Update(deltaTime);
	}

	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Clear()
{
	// ȭ���� (0,0)���� �̵�.
	SetCursorPosition(0, 0);
	int height = 25;
	for (int i = 0; i < height; ++i)
	{
		Log("                              \n");
	}

	// ȭ���� (0,0)���� �̵�.
	SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	Clear();														// ȭ�� �����.

	if (mainLevel != nullptr)										// ���� �׸���.
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
