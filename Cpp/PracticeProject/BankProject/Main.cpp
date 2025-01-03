#include <iostream>
#include "Bank.h"

void Loop()
{
	Bank bank;
	char input;
	char* name{};
	int id;
	int money;
	ACCOUNT_TYPE type;
	while (true)
	{
		std::cout << "1. �Ϲ� ����  2. �ſ� ����  3. ��� ����\n";
		std::cin >> input;
		while (true)
		{
			if (input == '1')
			{
				type = ACCOUNT_TYPE::ACCOUNT;
				break;
			}
			else if (input == '2')
			{
				type = ACCOUNT_TYPE::CREDIT_ACCOUNT;
				break;
			}
			else if (input == '3')
			{
				type = ACCOUNT_TYPE::DONATION_ACCOUNT;
				break;
			}
			else
			{
				std::cout << "�ٽ� �Է����ּ���.\n";
				std::cout << "1. �Ϲ� ����  2. �ſ� ����  3. ��� ����\n";
			}
		}
		std::cout << "1.���� ����  2.�Ա�  3.���  4.��ü �� �ܾ� ��ȸ\n";
		std::cin >> input;
		if (input == 'q' || input == 'Q')
		{
			break;
		}
		if (input == '1')				// ���� ����
		{
			std::cout << "�̸��� �Է����ּ���.\n";
			std::cin >> name;
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.CreateAccount(name, money, type);
		}
		else if (input == '2')			// �Ա�
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.Deposit(id, money, type);
		}
		else if (input == '3')			// ���
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "����� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.Withdraw(id, money, type);
		}
		else if (input == '4')			// ��ü �� �ܾ� ��ȸ
		{
			bank.Inquire(type);
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���.\n";
		}
	}
	if (name != nullptr)
	{
		delete[] name;
	}
}

int main()
{
	Loop();

	std::cin.get();
	return 0;
}