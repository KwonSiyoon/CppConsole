#include <iostream>
#include <functional>						// C++ 11 이상

// 함수 포인터 선언
void(*functionPointer)();					// 원형
typedef void (*functionTypePointer)();
using usingFunctionPointer = void(*)();
std::function<void()> newFunctionPointer;	// functional 헤더 사용

int main()
{
	// Lamda함수(무명함수)
	// 선언하면서 호출.

	// 람다함수 저장.
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
	
	functionPointer = []() { std::cout << "함수 포인터 선언됨\n"; };
	functionPointer();

	newFunctionPointer = functionPointer;
	newFunctionPointer();

	functionTypePointer funcPointer = functionPointer;
	funcPointer();
	usingFunctionPointer usingfuncPointer = functionPointer;
	usingfuncPointer();
}