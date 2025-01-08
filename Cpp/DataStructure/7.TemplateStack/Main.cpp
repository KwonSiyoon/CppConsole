#include "Stack.h"

int main()
{
	// 스택 객체.
	Stack<float> stack;

	std::cout << "첫 번째 게임 종료 - 경험치 140\n";
	stack.Push(140.0f);
	std::cout << "첫 번째 게임 종료 - 경험치 180\n";
	stack.Push(180.0f);
	std::cout << "첫 번째 게임 종료 - 경험치 200\n";
	stack.Push(200.0f);

	// 출력.
	/*int count = stack.Count();
	for (int i = 0; i < count; ++i)
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치: " << value << "\n";
		}
	}*/
	while (!stack.IsEmpty())
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치: " << value << "\n";
		}
	}


	std::cin.get();
}