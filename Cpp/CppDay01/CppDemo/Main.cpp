
// ��ó��(Pre-Process) -> iostream ���� ������ �ܾ� ��. 
#include<iostream>
#include "Log.h"
//using IntPtr = int*;
typedef int* IntPtr;
//void Log(const char* message);

// �Լ� �ȿ� ������ �ڵ带 �ܾ�ͼ� �Լ� ȣ�� �κп� �����ϰ� ����ִ� �� -> inline�̶� ��.
// #define -> ��ũ�� ����.
// #define Square(x) ((x) * (x)) // ��ũ��
// inline -> �ӵ��� ���, �뷮�� ����.
#define FORCEINLINE __forceinline // inline�� ���ϰ� ��û.
//inline int Square(int x) {
FORCEINLINE int Square(int x) {
	return x * x;
}

// ������(Entry Point) -> main �̶�� �̸��� �Լ��� ã��.
int main() {
	// �ּ�(Comment).
	
	// ���.
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	// �ǹ� ����. �ٷ� ������� ����� �߰�.
	std::cin.get(); // �ƹ� ���ڳ� �Էµ� �� �ְ� ���ִ� �Լ�.
}