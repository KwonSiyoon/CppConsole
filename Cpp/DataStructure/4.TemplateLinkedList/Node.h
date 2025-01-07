#pragma once

#include <iostream>


// ��ũ�帮��Ʈ�� ����� ��� Ŭ����.
// ���ø��� ��� ����� �ۼ��ؾ� ��.
template<typename T>
class Node
{
	//// std::cout �� ���� ����� �� �ֵ��� �����ε�.
	//friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// ����.
	template<typename T>
	friend class LinkedList;

public:
	// ������
	Node()
		: data() // Ÿ���� �⺻���� ã�Ƽ� ó������.
	{
		
	}
	Node(T data)
		: data(data)
	{

	}

private:
	// ������ �ʵ�.
	T data;

	// ��ũ �ʵ�.
	Node<T>* next = nullptr;
};

