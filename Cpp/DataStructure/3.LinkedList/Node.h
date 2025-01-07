#pragma once

#include <iostream>


// 링크드리스트의 요소인 노드 클래스.
class Node
{
	// std::cout 에 쉽게 출력할 수 있도록 오버로딩.
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// 예외.
	friend class LinkedList;

public:
	Node();
	Node(int data);

private:
	// 데이터 필드.
	int data = 0;

	// 링크 필드.
	Node* next = nullptr;
};

