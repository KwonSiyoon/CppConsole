#pragma once


class Actor;				// ���� ����
class ENGINE_API Level
{
public:
	Level();
	virtual ~Level();

	// ���� �߰� �Լ�.
	void AddActor(Actor* newActor);

	// ���� ó�� �Լ�.
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Actor** actors = nullptr;					// ���� ������ ��ġ�Ǵ� ��ü(����) �迭.
	int capacity = 4;							// ������ �� �ִ� ������ ũ��.
	int count = 0;								// ������ ��.
};
