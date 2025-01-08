#pragma once
#include <iostream>

template<typename T, int size = 10>
class Stack
{
public:
	Stack()
	{
		memset(data, 0, sizeof(T) * size);
	}

	// 초기화.
	void Clear()
	{
		count = 0;
	}

	// 스택에 저장된 요소의 수 반환.
	inline int Count() const
	{
		return count;
	}

	// 스택이 비었는지 확인하는 함수.
	inline bool IsEmpty() const
	{
		return count == 0;
	}

	// 스택이 가득 찼는지 확인하는 함수.
	inline bool IsFull() const
	{
		return count == size;
	}

	// 데이터 저장 함수.
	bool Push(T value)
	{
		// 예외 처리.
		if (IsFull())
		{
			std::cout << "스택이 가득차 저장 실패\n";
			return false;
		}

		// 저장 및 카운트 증가.
		data[count] = value;
		++count;
		return true;
	}

	// 데이터 출력(삭제) 함수.
	bool Pop(T& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "스택이 비어서 데이터 출력 실패\n";
			return false;
		}

		--count;
		outValue = data[count];
		return true;
	}

private:
	// 데이터 저장 배열.
	T data[size];

	// 스택에 저장된 요소의 수(top/head).
	int count = 0;
};