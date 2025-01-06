#include <iostream>
#include <array>

template<typename T, size_t size>
class Array
{
public:
	//Array(size_t size)
	//	:count(size)
	//{
	//	data[size];
	//}

	T& operator[](int index)
	{
		return data[index];
	}

	size_t Count() const { return size; }
private:
	T data[size];
};



int main()
{
	//int array[10] = { 0,1,2,3,4,5,6,7,8,9 };										// ũ�Ⱑ 10�� int�� �迭.
		


	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };					// �� �迭.


	delete[] heapArray;																// ����.


	Array<int,10> arrayObject;															// �迭 ��ü.
	arrayObject[0] = 10;
	arrayObject[1] = 20;
	arrayObject[2] = 30;


	std::array<int, 10> array;


	std::cin.get();
}