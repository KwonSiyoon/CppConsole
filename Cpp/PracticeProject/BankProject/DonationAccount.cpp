#include "DonationAccount.h"

DonationAccount::DonationAccount()
	: Account(0, nullptr, 0), donation(0)
{
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::Deposit(float money)
{
	donation += money * donationRate;
}

void DonationAccount::Withdraw(int money)
{
}

void DonationAccount::Print()
{
}
