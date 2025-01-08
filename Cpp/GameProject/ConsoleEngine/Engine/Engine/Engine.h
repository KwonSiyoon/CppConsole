#pragma once

#include "Core.h"
#include "Math/Vector2.h"

struct KeyState										// �Է� ó���� ���� ����ü.
{
	bool isKeyDown = false;							// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��.
	bool wasKeyDown = false;						// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��.
};

// Ŀ���� ������ ������ �� ����� ������.
enum class CursorType
{
	NoCursor,
	SolidCursor,
	NormalCursor
};


class Level;
class ENGINE_API Engine										// ���� Ŭ����.
{
public:
	Engine();
	virtual ~Engine();

	void Run();										// ���� ���� �Լ�.
	
	void LoadLevel(Level* newLevel);				// ���� ��ȯ �Լ�.

	// ȭ�� ��ǥ ���� �Լ�.
	void SetCursorType(CursorType cursorType);
	void SetCursorPosition(const Vector2& position);
	void SetCursorPosition(int x, int y);

	void SetTargetFrameRate(float targetFrameRate); // Ÿ�� ������ �ӵ� ���� �Լ�.

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

protected:
	float targetFrameRate = 60.0f;					// Ÿ�� ������ ����(�ʴ� ������).
	float targetOneFrameTime = 0.0f;				// �� ������ �ð� ��(���� : ��).
	bool quit;										// ������ �� ������ ����.
	KeyState keyState[255];							// Ű ���¸� �����ϴ� �迭.
	static Engine* instance;						// �̱��� ������ ���� ���� ���� ����.
	Level* mainLevel;								// ���� ���� ����.

};

