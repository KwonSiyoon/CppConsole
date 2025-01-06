#pragma once

#include "Core.h"

struct KeyState										// �Է� ó���� ���� ����ü.
{
	bool isKeyDown = false;							// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��.
	bool wasKeyDown = false;						// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��.
};


class Level;
class ENGINE_API Engine										// ���� Ŭ����.
{
public:
	Engine();
	virtual ~Engine();

	void Run();										// ���� ���� �Լ�.
	
	void LoadLevel(Level* newLevel);				// ���� ��ȯ �Լ�.

	bool GetKey(int key);							// �Է� ���� �Լ�.
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	void QuitGame();								// ���� ���� �Լ�.
	static Engine& Get();							// �̱��� ��ü ���� �Լ�.

protected:
	void ProcessInput();							// �Է� ó��.
	void Update(float deltaTime);					// Tick();
	void Draw();									// Render();

	void SavePreviouseKeyStates();					// ���� �������� Ű ���¸� �����ϴ� �Լ�.

private:
	bool quit;										// ������ �� ������ ����.
	KeyState keyState[255];							// Ű ���¸� �����ϴ� �迭.
	static Engine* instance;						// �̱��� ������ ���� ���� ���� ����.
	Level* mainLevel;								// ���� ���� ����.

};

