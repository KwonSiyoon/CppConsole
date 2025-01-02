#include "Bank.h"

Bank::Bank()
	: count(0)
{
}

Bank::~Bank()
{
	// 메모리 해제.
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
	std::cout << "선택: ";
	std::cout << "====== 메뉴 ======\n";
	std::cout << "1. 계좌 개설\n";
	std::cout << "2. 입금\n";
	std::cout << "3. 출금\n";
	std::cout << "4. 잔액 조회\n";
	std::cout << "5. 프로그램 종료\n";
}

void Bank::CreateAccount()
{
	// 사용자에게 입력 받을 데이터를 위한 변수 선언.
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

