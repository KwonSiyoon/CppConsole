#include "DonationAccount.h"
#include "Account.h"
#include <iostream>

DonationAccount::DonationAccount()
	: Account(), donation(0)
{
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::Deposit(int money)
{
	donation += money * donationRate;
}

void DonationAccount::Withdraw(int money)
{
}

void DonationAccount::Print()
{
	std::cout << "기부 금액 : " << donation << " 원\n";
}
