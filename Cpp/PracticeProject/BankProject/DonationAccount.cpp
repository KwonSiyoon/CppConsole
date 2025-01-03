#include <iostream>
#include "Account.h"
#include "DonationAccount.h"

DonationAccount::DonationAccount()
	: Account(), donation(0)
{
}

DonationAccount::DonationAccount(int id, const char* name, int money)
	: Account(id, name, money), donation(0)
{
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::Deposit(int money)
{
	Account::Deposit(money);
	donation += money * donationRate;
}

void DonationAccount::Withdraw(int money)
{
	Account::Withdraw(money);
}

void DonationAccount::Print()
{
	Account::Print();
	std::cout << "기부 금액 : " << donation << " 원\n";
}
