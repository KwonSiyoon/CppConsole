#include "PreCompiledHeader.h"
#include <iostream>
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
	: actors(nullptr), capacity(4), count(0)
{
	actors = new Actor* [capacity];								// 동적 배열 생성.
	memset(actors, 0, sizeof(size_t) * capacity);				// 초기화.
}

Level::~Level()
{
	// 메모리 해제.
	for (int i = 0; i < count; ++i)
	{
		// 액터 삭제.
		if (actors != nullptr)
		{
			delete actors[i];
		}
	}

	// 동적 배열 해제.
	delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
	// 현재 할당된 공간이 충분한지 확인.
	if (count == capacity)
	{
		// 공간 추가 할당.
		int newCapacity = capacity * 2;							// 공간을 2배로.
		Actor** temp = new Actor* [newCapacity];				// 임시 공간.
		memcpy(temp, actors, sizeof(size_t) * capacity);		// 기존 값 복사.
		delete[] actors;										// 기존 배열 삭제.
		actors = temp;											// 배열 교체.
		capacity = newCapacity;									// 크기 변경.
	}

	// 액터 추가.
	actors[count] = newActor;
	++count;
}

void Level::Update(float deltaTime)
{
	// 레벨에 포함된 액터를 순회하면서 Update 함수 호출.
	for (int i = 0; i < count; ++i)
	{
		actors[i]->Update(deltaTime);
	}
}

void Level::Draw()
{
	// 레벨에 포함된 액터를 순회하면서 Draw 함수 호출.
	for (int i = 0; i < count; ++i)
	{
		actors[i]->Draw();
	}
}
