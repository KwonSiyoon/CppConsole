#include <iostream>

// ������(Entry Point).
int main() {

	//auto testString = "Hello";
	const char* testString = "Hello";
	char charArray[] = "Hello";

	// ���� �Ҵ�.
	size_t length = strlen("Ronnie") + 1;
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");


	std::cout << testString << "\n";
	std::cout << charArray << "\n";
	std::cout << name << "\n";

	
	//delete[] name;

	std::cin.get();
	return 0;
}