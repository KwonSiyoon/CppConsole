#include <iostream>
#include "Bank.h"


enum class MenuType																	// ������.
{
	None = -1,
	Create = 1,
	Deposit,
	Withdraw,
	Inquire,
	Exit,
	Length
};


void ClearScreen()																	// ȭ�� ����� �Լ�
{
	system("cls");
}

int main()
{
	Bank* bank = new Bank;
	int choice = 0;																	// �޴� ���� �Է� �ޱ�.

	MenuType menuType;																// ���� �޴� ������ ����.

	char tempBuffer[100]{};

	while (true)																	// ����
	{
		
		std::cin >> choice;

		if (choice = atoi(tempBuffer))												// ������ ��ȯ�� �������� Ȯ��.
		{
			if (choice >= 1 && choice <= 5)											// �Է� �� Ȯ��.
			{
				menuType = static_cast<MenuType>(choice);
				switch (menuType)													// �޴� ����.
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
					// �޸� ����.
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
			std::cout << "�߸� �Է��ϼ̽��ϴ�.\n";
		}
	}
}