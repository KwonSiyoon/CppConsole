#include "Bank.h"

Bank::Bank()
	: count(0)
{
}

Bank::~Bank()
{
	// �޸� ����.
	for (int ix = 0; ix < count; ++ix)
	{
		if (accounts[ix] != nullptr)
		{
			delete accounts[ix];
		}
	}
}

void Bank::PrintMenu()
{
	std::cout << "����: ";
	std::cout << "====== �޴� ======\n";
	std::cout << "1. ���� ����\n";
	std::cout << "2. �Ա�\n";
	std::cout << "3. ���\n";
	std::cout << "4. �ܾ� ��ȸ\n";
	std::cout << "5. ���α׷� ����\n";
}

void Bank::CreateAccount()
{
	// ����ڿ��� �Է� ���� �����͸� ���� ���� ����.
	int id = 0;
	char name[50]{};
	int balance = 0;
	
}

void Bank::Deposit()
{
}

void Bank::Withdraw()
{
}

void Bank::Inquire()
{
}

