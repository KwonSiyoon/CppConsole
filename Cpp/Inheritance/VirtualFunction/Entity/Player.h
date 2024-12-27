#pragma once
#include "Entity.h"
#include "IMovable.h"
#include <iostream>

// Entity 클래스를 부모로 지정.
// 미들웨어 (운영체제 위에서 동작하는 프로그램). -> 현재 하는것들.
// 다중상속. 여러부모를 가짐. 그러나 안하는게 좋음.
class Player :	public IEntity, IMovable
{
public:
	Player(const char* name);
	~Player();							// 소멸자에는 virtual, override를 안붙여줘도 됨. 
	//virtual ~Player();				// 또 다시 자식을 가지게 될 경우 앞에 virtual 붙이기.

	virtual void Move(int xAmount, int yAmount) override { std::cout << "Move\n"; }
	virtual const char* GetName() override { return name; }
	//{
	//	// :: => 범위 지정 연산자.
	//	//std::cout << Entity::GetName() << "\n";
	//	return name; 
	//}

private:
	char* name{};
};

