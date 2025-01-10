#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{
	
}

Level::~Level()
{
	// �޸� ����.
	//for (int i = 0; i < actors.Size(); ++i)		// for�� ���
	//{
	//	// ���� ����.
	//	delete actors[i];
	//}
	for (Actor* actor : actors)					// foreach ���
	{
		// ���� ����.
		delete actor;
	}
	// ���� �迭 ����.
	//delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
	actors.PushBack(newActor);
}

void Level::DestroyActor()
{
	// ���� ��ȸ �� ���� ��û�� ���͸� ó��.
	for (int i = 0; i < actors.Size();)
	{
		if (actors[i]->isExpired)
		{
			delete actors[i];
			actors[i] = nullptr;
			actors.Erase(i);
			continue;
		}
		++i; // ���� ������ ���� ����ó��.
	}
}

void Level::Update(float deltaTime)
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��.
	for (Actor* actor : actors)
	{
		// ���Ͱ� ��Ȱ��ȭ �����̰ų�, ���� ��û�� ��� �ǳʶٱ�.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}
		actor->Update(deltaTime);
	}
}

void Level::Draw()
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��.
	for (Actor* actor : actors)
	{
		// ���Ͱ� ��Ȱ��ȭ �����̰ų�, ���� ��û�� ��� �ǳʶٱ�.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}
		actor->Draw();
	}
}
