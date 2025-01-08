#pragma once

#include "Core.h"
#include "Math/Vector2.h"

struct KeyState										// 입력 처리를 위한 구조체.
{
	bool isKeyDown = false;							// 현재 프레임에 키가 눌렸는지 확인.
	bool wasKeyDown = false;						// 이전 프레임에 키가 눌렸었는지 확인.
};

// 커서의 종류를 설정할 때 사용할 열거형.
enum class CursorType
{
	NoCursor,
	SolidCursor,
	NormalCursor
};


class Level;
class ENGINE_API Engine										// 엔진 클래스.
{
public:
	Engine();
	virtual ~Engine();

	void Run();										// 엔진 실행 함수.
	
	void LoadLevel(Level* newLevel);				// 레벨 전환 함수.

	// 화면 좌표 관련 함수.
	void SetCursorType(CursorType cursorType);
	void SetCursorPosition(const Vector2& position);
	void SetCursorPosition(int x, int y);

	void SetTargetFrameRate(float targetFrameRate); // 타겟 프레임 속도 설정 함수.

	bool GetKey(int key);							// 입력 관련 함수.
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	void QuitGame();								// 엔진 종료 함수.
	static Engine& Get();							// 싱글톤 객체 접근 함수.

protected:
	void ProcessInput();							// 입력 처리.
	void Update(float deltaTime);					// Tick();
	void Draw();									// Render();

	void SavePreviouseKeyStates();					// 이전 프레임의 키 상태를 저장하는 함수.

protected:
	float targetFrameRate = 60.0f;					// 타겟 프레임 변수(초당 프레임).
	float targetOneFrameTime = 0.0f;				// 한 프레임 시간 값(단위 : 초).
	bool quit;										// 종료할 때 설정할 변수.
	KeyState keyState[255];							// 키 상태를 저장하는 배열.
	static Engine* instance;						// 싱글촌 구현을 위한 전역 변수 선언.
	Level* mainLevel;								// 메인 레벨 변수.

};

