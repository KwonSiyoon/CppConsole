#pragma once


class Actor;				// 전방 선언
class ENGINE_API Level
{
public:
	Level();
	virtual ~Level();

	// 액터 추가 함수.
	void AddActor(Actor* newActor);

	// 루프 처리 함수.
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Actor** actors = nullptr;					// 게임 공간에 배치되는 물체(액터) 배열.
	int capacity = 4;							// 저장할 수 있는 공간의 크기.
	int count = 0;								// 액터의 수.
};
