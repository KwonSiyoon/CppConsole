#include <iostream>
#include "Account.h"
#include "DonationAccount.h"

DonationAccount::DonationAccount()
	: Account(), donation(0)
{
}

DonationAccount::DonationAccount(int id, const char* name, int money, int donation)
	: Account(id, name, money), donation(donation)
{
}

DonationAccount::~DonationAccount()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
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

const int DonationAccount::GetID()
{
	return id;
}

const char* DonationAccount::GetName()
{
	return name;
}

const int DonationAccount::GetBalance()
{
	return balance;
}

const int DonationAccount::GetDonation()
{
	return donation;
}
