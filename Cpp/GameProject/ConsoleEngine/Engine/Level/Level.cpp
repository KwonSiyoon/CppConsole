#include "PreCompiledHeader.h"
#include <iostream>
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
	: actors(nullptr), capacity(4), count(0)
{
	actors = new Actor* [capacity];								// ���� �迭 ����.
	memset(actors, 0, sizeof(size_t) * capacity);				// �ʱ�ȭ.
}

Level::~Level()
{
	// �޸� ����.
	for (int i = 0; i < count; ++i)
	{
		// ���� ����.
		if (actors != nullptr)
		{
			delete actors[i];
		}
	}

	// ���� �迭 ����.
	delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
	// ���� �Ҵ�� ������ ������� Ȯ��.
	if (count == capacity)
	{
		// ���� �߰� �Ҵ�.
		int newCapacity = capacity * 2;							// ������ 2���.
		Actor** temp = new Actor* [newCapacity];				// �ӽ� ����.
		memcpy(temp, actors, sizeof(size_t) * capacity);		// ���� �� ����.
		delete[] actors;										// ���� �迭 ����.
		actors = temp;											// �迭 ��ü.
		capacity = newCapacity;									// ũ�� ����.
	}

	// ���� �߰�.
	actors[count] = newActor;
	++count;
}

void Level::Update(float deltaTime)
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��.
	for (int i = 0; i < count; ++i)
	{
		actors[i]->Update(deltaTime);
	}
}

void Level::Draw()
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��.
	for (int i = 0; i < count; ++i)
	{
		actors[i]->Draw();
	}
}
