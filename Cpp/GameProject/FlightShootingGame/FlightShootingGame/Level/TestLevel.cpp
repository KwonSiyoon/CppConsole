#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"

TestLevel::TestLevel()
{
	AddActor(new Player("<A>"));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);			// 커스텀 RTTI 사용시 Level 대신 Super를 통해 호출 가능.

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}
