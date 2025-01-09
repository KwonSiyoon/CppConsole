#pragma once
#include <iostream>

// 큐의 최대 크기.
const int maxSize = 100;

// 큐 클래스.
class Queue
{
public:
	Queue()
	{
		// 배열의 초기 값을 0으로 설정.
		memset(data, 0, sizeof(int) * maxSize);
	}

	// 큐가 비었는지 확인하는 함수.
	bool IsEmpty() const
	{
		return front == rear;
	}
	// 큐가 가득찼는지 확인하는 함수.
	bool IsFull() const
	{
		return (rear + 1) % maxSize == front;
	}
	// 데이터 추가.
	void Enqueue(int value)
	{
		if (IsFull())
		{
			std::cout << "Error: 큐가 가득참.\n";
			return;
		}
		// 데이터 추가할 인덱스 계산 후 삽입.
		rear = (rear + 1) % maxSize;
		data[rear] = value;
	}

	// 데이터 추출.
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error: 큐가 비어있음.\n";
			return false;
		}

		// 데이터 추출할 위치를 찾아서 추출.
		front = (front + 1) % maxSize;
		outValue = data[front];
		return true;
	}

	// 출력.
	void Print()
	{
		std::cout << "큐 내용: ";
		int max = (front < rear) ? rear : rear + maxSize;
		for (int i = front + 1; i <= max; ++i)
		{
			std::cout << data[i % maxSize] << " ";
		}

		/*while (!IsEmpty())
		{
			int value = 0;
			if (Dequeue(value))
			{
				std::cout << value << " ";

			}
		}*/
		std::cout << "\n";

	}

private:
	int front = 0;					// 데이터가 출력되는 위치.
	int rear = 0;					// 데이터가 입력되는 위치.
	int data[maxSize];			// 데이터 저장소.

};