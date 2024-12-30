#include <iostream>

// int 타입 값 바꾸기.
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

// 템플릿.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	int number1 = 10;
	int number2 = 20;

	Swap(number1, number2);
	std::cout << number1 << " : " << number2 << "\n";

	float num1 = 10.0f;
	float num2 = 20.0f;

	Swap(num1, num2);
	std::cout << num1 << " : " << num2 << "\n";


	std::cin.get();
}


