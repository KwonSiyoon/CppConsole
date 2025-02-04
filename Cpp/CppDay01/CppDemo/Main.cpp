
// 전처리(Pre-Process) -> iostream 파일 내용을 긁어 옴. 
#include<iostream>
#include "Log.h"
//using IntPtr = int*;
typedef int* IntPtr;
//void Log(const char* message);

// 함수 안에 구현된 코드를 긁어와서 함수 호출 부분에 삭제하고 집어넣는 것 -> inline이라 함.
// #define -> 매크로 선언.
// #define Square(x) ((x) * (x)) // 매크로
// inline -> 속도를 얻고, 용량을 잃음.
#define FORCEINLINE __forceinline // inline을 강하게 요청.
//inline int Square(int x) {
FORCEINLINE int Square(int x) {
	return x * x;
}

// 진입점(Entry Point) -> main 이라는 이름의 함수를 찾자.
int main() {
	// 주석(Comment).
	
	// 출력.
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	// 의미 없음. 바로 종료되지 말라고 추가.
	std::cin.get(); // 아무 문자나 입력될 수 있게 해주는 함수.
}