#pragma once


// Ŭ���� ����.
class IEntity
{
public:
//	Entity();
//	virtual ~Entity();
//
//	void Move(int xAmount, int yAmount);
	//virtual const char* GetName() const { return "Entity"; }

	// ���� �����Լ�(Pure Virtual Function).
	// ����: �� �Լ��� �ʼ������� �����ϵ��� ������.
	virtual const char* GetName() = 0;

//protected:
//	int x;
//	int y;
};

