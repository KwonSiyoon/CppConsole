#pragma once


// 클래스 선언.
class Entity
{
public:
	Entity();
	~Entity();

	void Move(int xAmount, int yAmount);

protected:
	int x;
	int y;
};

