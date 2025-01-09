#include <iostream>

// 呼靛 : 哪颇老 -> 傅目 -> exe 积己. 鉴辑
// Main.cpp -> 哪颇老 -> Main.obj 积己.
// 傅目(Linker) -> Library.lib
// exe 积己.

// 1瞒 规过
//class Math
//{
//public:
//	static int Add(int a, int b);
//	static int Substract(int a, int b);
//	static int Multiply(int a, int b);
//	static int Divide(int a, int b);
//};

// 2瞒 规过.
#include "MyMath.h"

int main()
{
	std::cout << "Hello\n";

	std::cout << "10 + 20 = " << Math::Add(10, 20) << "\n";
	std::cout << "10 - 20 = " << Math::Substract(10, 20) << "\n";

	std::cin.get();
}