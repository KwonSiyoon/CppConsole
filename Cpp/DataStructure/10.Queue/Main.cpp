#include "Queue.h"

int main()
{
	Queue queue;
	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 10);
	}
	queue.Print();

	std::cout << "====== ť ��� ����====\n";

	int value = 0;
	queue.Enqueue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Print();

}