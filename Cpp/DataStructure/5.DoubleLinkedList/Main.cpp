#include <iostream>
#include "LinkedList.h"

// 오류 함수.
// 이벤트 리스너(Listener) 함수.
void OnListEmptyError()
{
	std::cout << "데이터가 없습니다.\n";
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

	std::cout << "------ 리스트 출력 -------\n";
	list.Print();

	list.AddToLast(100);
	list.AddToLast(90);
	list.AddToLast(80);
	list.AddToLast(70);
	list.AddToLast(60);

	std::cout << "------ 리스트 출력 -------\n";
	list.Print();

	list.Delete(100);
	list.Delete(80);
	list.Delete(60);
	list.Delete(40);

	std::cout << "------ 리스트 출력 -------\n";
	list.Print();

	std::cout << "Data : " << list.Find(90)->Data() << "\n";
	std::cout << "Data : " << list.Find(80)->Data() << "\n";
	Node<int>* node = list.Find(80);
	if (list.Find(70, node))
	{
		if (node != nullptr)  // 추가적인 nullptr 체크
		{
			std::cout << "Data : " << node->Data() << "\n";
		}
	}
	std::cout << "Data : " << list.Find(90) << "\n";


	std::cin.get();


}