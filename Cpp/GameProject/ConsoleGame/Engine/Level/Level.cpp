﻿#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{
	
}

Level::~Level()
{
	// 메모리 해제.
	//for (int i = 0; i < actors.Size(); ++i)		// for문 방법
	//{
	//	// 액터 삭제.
	//	delete actors[i];
	//}
	for (Actor* actor : actors)					// foreach 방법
	{
		// 액터 삭제.
		delete actor;
	}
	// 동적 배열 해제.
	//delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
	//actors.PushBack(newActor);
    addRequestedActor = newActor;
}

void Level::ProcessAddedAndDestroyedActor()
{
    // 액터 순회 후 삭제 요청된 액터를 처리.
    for (int i = 0; i < actors.Size();)
    {
        if (actors[i]->isExpired)
        {
        	delete actors[i];
        	actors[i] = nullptr;
        	actors.Erase(i);
        	continue;
        }
        ++i; // 삭제 안했을 때만 증가처리.
    }

    // 추가 요청된 액터 처리.
    if (addRequestedActor)
    {
        actors.PushBack(addRequestedActor);
        addRequestedActor = nullptr;
    }
}

void Level::Update(float deltaTime)
{
	// 레벨에 포함된 액터를 순회하면서 Update 함수 호출.
	for (Actor* actor : actors)
	{
		// 액터가 비활성화 상태이거나, 삭제 요청된 경우 건너뛰기.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}
		actor->Update(deltaTime);
	}
}

void Level::Draw()
{
	// 레벨에 포함된 액터를 순회하면서 Draw 함수 호출.
	for (Actor* actor : actors)
	{
		// 액터가 비활성화 상태이거나, 삭제 요청된 경우 건너뛰기.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}
		actor->Draw();
	}
}
