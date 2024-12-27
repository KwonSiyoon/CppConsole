#pragma once
#include "Entity.h"
#include "IMovable.h"
#include <iostream>

// Entity Ŭ������ �θ�� ����.
// �̵���� (�ü�� ������ �����ϴ� ���α׷�). -> ���� �ϴ°͵�.
// ���߻��. �����θ� ����. �׷��� ���ϴ°� ����.
class Player :	public IEntity, IMovable
{
public:
	Player(const char* name);
	~Player();							// �Ҹ��ڿ��� virtual, override�� �Ⱥٿ��൵ ��. 
	//virtual ~Player();				// �� �ٽ� �ڽ��� ������ �� ��� �տ� virtual ���̱�.

	virtual void Move(int xAmount, int yAmount) override { std::cout << "Move\n"; }
	virtual const char* GetName() override { return name; }
	//{
	//	// :: => ���� ���� ������.
	//	//std::cout << Entity::GetName() << "\n";
	//	return name; 
	//}

private:
	char* name{};
};

