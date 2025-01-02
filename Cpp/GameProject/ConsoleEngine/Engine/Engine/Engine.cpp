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
	//unsigned long currentTime = timeGetTime();					// ���� Ÿ�� ������ ����.
	//unsigned long previousTime = 0;


	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	
	LARGE_INTEGER time;									// ���۽ð� �� �����ð��� ���� ����.
	QueryPerformanceCounter(&time);

	//__int64 currentTime = time.QuadPart;
	int64_t currentTime = time.QuadPart;
	//__int64 previousTime = 0;
	int64_t previousTime = 0;

	float targetFrameRate = 1000.01f;								// ������ ����.

	float targetOneFrameTime = 1.0f / targetFrameRate;			// �� ������ �ð� ���.

	

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




		if (deltaTime >= targetOneFrameTime)					// ������ Ȯ��.
		{

			ProcessInput();										// �Է� ó�� ( ���� Ű�� ���� ���� Ȯ��)
			Update(deltaTime);
			Draw();

			SavePreviouseKeyStates();							// Ű ���� ����.

			previousTime = currentTime;							// ���� ������ �ð� ����.
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
	quit = true;													// ���� �÷��� ����.
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
	if (GetKeyDown(VK_ESCAPE))										// ESCŰ�� ���� ����.
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
