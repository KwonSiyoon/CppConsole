#pragma once
#include "Entity.h"

// Entity Ŭ������ �θ�� ����.
// �̵���� (�ü�� ������ �����ϴ� ���α׷�). -> ���� �ϴ°͵�.
class Player :	public Entity
{
public:
	Player(const char* name);
	~Player();
private:
	char* name{};
};

