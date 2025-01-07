#pragma once

#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void AddToHead(int data);		// ��忡 �߰��ϴ� �Լ�.
	void Insert(int data);			// �� �ڿ� �����ϴ� �Լ�.
	void Delete(int data);			// �����͸� ������ �˻� �� �����ϴ� �Լ�.
	void Print();					// ����� ��� ��� �Լ�.
	inline int Count() const;		// ����� ����� ���� ��ȯ�ϴ� �Լ�(Getter).

private:
	// ���(����) ���.
	Node* head = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;

};