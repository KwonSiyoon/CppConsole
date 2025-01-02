#include <iostream>
#include "Bank.h"


enum class MenuType																	// 열거형.
{
	None = -1,
	Create = 1,
	Deposit,
	Withdraw,
	Inquire,
	Exit,
	Length
};


void ClearScreen()																	// 화면 지우는 함수
{
	system("cls");
}

int main()
{
	Bank* bank = new Bank;
	int choice = 0;																	// 메뉴 선택 입력 받기.

	MenuType menuType;																// 선택 메뉴 열거형 선언.

	char tempBuffer[100]{};

	while (true)																	// 루프
	{
		
		std::cin >> choice;

		if (choice = atoi(tempBuffer))												// 정수로 변환이 가능한지 확인.
		{
			if (choice >= 1 && choice <= 5)											// 입력 값 확인.
			{
				menuType = static_cast<MenuType>(choice);
				switch (menuType)													// 메뉴 선택.
				{
				case MenuType::None:
					break;
				case MenuType::Create:
					break;
				case MenuType::Deposit:
					break;
				case MenuType::Withdraw:
					break;
				case MenuType::Inquire:
					break;
				case MenuType::Exit:
					// 메모리 해제.
					delete bank;
					return 0;
					break;
				case MenuType::Length:
					break;
				default:
					break;
				}
			}
		}
		else
		{
			std::cout << "잘못 입력하셨습니다.\n";
		}
	}
}