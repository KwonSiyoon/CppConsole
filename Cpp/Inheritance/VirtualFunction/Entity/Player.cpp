#include "Player.h"
#include <iostream>

Player::Player(const char* name) : IEntity()
{
	std::cout << "Player() called\n";

	// 동적 할당 및 설정.
	size_t length = strlen(name);

	// 동적 할당.
	this->name = new char[length + 1];

	// 문자열 복사.
	strcpy_s(this->name, length + 1, name);
}

Player::~Player()
{
	std::cout << "~Player() called\n";

	// 메모리 해제.
	// false -> 0, 나머지는 true.
	// if(name) -> 이렇게 해도 작동.
	if (name != nullptr)
	{
		delete[] name;
	}
}
