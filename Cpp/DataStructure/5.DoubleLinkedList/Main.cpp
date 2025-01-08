#include <iostream>
#include "LinkedList.h"

// ���� �Լ�.
// �̺�Ʈ ������(Listener) �Լ�.
void OnListEmptyError()
{
	std::cout << "�����Ͱ� �����ϴ�.\n";
}


int main()
{
	LinkedList<int> list(OnListEmptyError);
	list.Delete(100);

	list.AddToFirst(10);
	list.AddToFirst(20);
	list.AddToFirst(30);
	list.AddToFirst(40);
	list.AddToFirst(50);
	list.AddToFirst(60);

	std::cout << "------ ����Ʈ ��� -------\n";
	list.Print();

	list.AddToLast(100);
	list.AddToLast(90);
	list.AddToLast(80);
	list.AddToLast(70);
	list.AddToLast(60);

	std::cout << "------ ����Ʈ ��� -------\n";
	list.Print();

	list.Delete(100);
	list.Delete(80);
	list.Delete(60);
	list.Delete(40);

	std::cout << "------ ����Ʈ ��� -------\n";
	list.Print();

	std::cout << "Data : " << list.Find(90)->Data() << "\n";
	std::cout << "Data : " << list.Find(80)->Data() << "\n";
	Node<int>* node = list.Find(80);
	if (list.Find(70, node))
	{
		if (node != nullptr)  // �߰����� nullptr üũ
		{
			std::cout << "Data : " << node->Data() << "\n";
		}
	}
	std::cout << "Data : " << list.Find(90) << "\n";


	std::cin.get();


}