#include <iostream>
#include "LinkedList.h"


class Test
{
public:
	Test(int data)
		: data(data)
	{

	}

	friend std::ostream& operator<<(std::ostream& os, const Test& test)
	{
		os << "Data: " << test.data;
		return os;
	}

	bool operator>=(const Test& data)
	{
		return this->data >= data.data;
	}

private:
	int data;
};

int main()
{
	LinkedList<int> list;
	LinkedList<Test> testList;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(40);
	list.Insert(50);

	testList.Insert(Test(10));

	std::cout << "------- 리스트 데이터 출력 --------\n";
	list.Print();
	testList.Print();

	list.Delete(30);
	list.Delete(50);
	list.Delete(0);
	list.Delete(540);

	std::cout << "-------- 데이터 삭제 후 출력 ------\n";
	list.Print();

	std::cin.get();
}