#pragma once


// 클래스 선언.
class IEntity
{
public:
//	Entity();
//	virtual ~Entity();
//
//	void Move(int xAmount, int yAmount);
	//virtual const char* GetName() const { return "Entity"; }

	// 순수 가상함수(Pure Virtual Function).
	// 목적: 이 함수를 필수적으로 구현하도록 강제함.
	virtual const char* GetName() = 0;

//protected:
//	int x;
//	int y;
};

