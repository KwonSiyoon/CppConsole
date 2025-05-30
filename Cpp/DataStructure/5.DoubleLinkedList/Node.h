#pragma once

#include <iostream>


// 링크드리스트의 요소인 노드 클래스.
// 템플릿은 모두 헤더에 작성해야 함.
template<typename T>
class Node
{
	//// std::cout 에 쉽게 출력할 수 있도록 오버로딩.
	//friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// 예외.
	template<typename T>
	friend class LinkedList;

public:
	// 생성자
	Node()
		: data() // 타입의 기본값을 찾아서 처리해줌.
	{
		
	}
	Node(T data)
		: data(data)
	{

	}
	T Data() const
	{
		return data;
	}

private:
	// 데이터 필드.
	T data;

	// 링크 필드.
	Node<T>* next = nullptr;

	Node<T>* previous = nullptr;
};

