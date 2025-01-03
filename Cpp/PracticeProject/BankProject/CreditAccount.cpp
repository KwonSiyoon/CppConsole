#include <iostream>
#include "Account.h"
#include "CreditAccount.h"

CreditAccount::CreditAccount()
	: Account(), interest(0)
{
}

CreditAccount::CreditAccount(int id, const char* name, int money)
	: Account(id, name, money), interest(0)
{
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::Deposit(int money)
{
	Account::Deposit(money);
	interest += money * interestRate;
}

void CreditAccount::Withdraw(int money)
{
	Account::Withdraw(money);
}

void CreditAccount::Print()
{
	Account::Print();
	std::cout << "이자 금액 : " << interest << " 원\n";
}

