#include <iostream>
#include <functional>						// C++ 11 �̻�

// �Լ� ������ ����
void(*functionPointer)();					// ����
typedef void (*functionTypePointer)();
using usingFunctionPointer = void(*)();
std::function<void()> newFunctionPointer;	// functional ��� ���

int main()
{
	// Lamda�Լ�(�����Լ�)
	// �����ϸ鼭 ȣ��.

	// �����Լ� ����.
	auto function = []() {std::cout << "Hello Lamda.\n"; };
	auto function1 = []() -> float { return 100; };
	function();
	std::cout << function1() << "\n";

	int count = 0;
	auto function2 = [&count]() {++count; };
	auto function3 = [](int& count) {++count; };
	auto function4 = [&]() {++count; };
	function2();
	function2();
	function2();
	function2();
	function2();
	std::cout << count << "\n";
	function3(count);
	function3(count);
	function3(count);
	function3(count);
	function3(count);
	std::cout << count << "\n";
	function4();
	function4();
	function4();
	function4();
	std::cout << count << "\n";
	
	functionPointer = []() { std::cout << "�Լ� ������ �����\n"; };
	functionPointer();

	newFunctionPointer = functionPointer;
	newFunctionPointer();

	functionTypePointer funcPointer = functionPointer;
	funcPointer();
	usingFunctionPointer usingfuncPointer = functionPointer;
	usingfuncPointer();
}