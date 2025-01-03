#include "CreditAccount.h"
#include "Account.h"
#include <iostream>

CreditAccount::CreditAccount()
	: Account(), interest(0)
{
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::Deposit(int money)
{
	interest += money * interestRate;
}

void CreditAccount::Withdraw(int money)
{
}

void CreditAccount::Print()
{
	std::cout << "기부 금액 : " << interest << " 원\n";
}

