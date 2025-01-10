#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 10);
	}
	std::cout << "======= ������ �߰� �� ��� =====\n";
	queue.Print();


	int outValue = 0;
	int count = 0;
	while (count < 3)
	{
		++count;
		if (queue.Dequeue(outValue))
		{
			std::cout << "ť���� ��µ� ��: " << outValue << "\n";
		}
	}
	std::cout << "======== ������ ���� �� ��� =======\n";
	queue.Print();



}