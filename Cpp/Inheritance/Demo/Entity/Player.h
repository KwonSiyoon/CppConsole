#pragma once
#include "Entity.h"

// Entity 클래스를 부모로 지정.
// 미들웨어 (운영체제 위에서 동작하는 프로그램). -> 현재 하는것들.
class Player :	public Entity
{
public:
	Player(const char* name);
	~Player();
private:
	char* name{};
};

