#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 10);
	}
	std::cout << "======= 데이터 추가 후 출력 =====\n";
	queue.Print();


	int outValue = 0;
	int count = 0;
	while (count < 3)
	{
		++count;
		if (queue.Dequeue(outValue))
		{
			std::cout << "큐에서 출력된 값: " << outValue << "\n";
		}
	}
	std::cout << "======== 데이터 삭제 후 출력 =======\n";
	queue.Print();



}