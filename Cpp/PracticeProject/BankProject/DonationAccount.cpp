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
	std::cout << "��� �ݾ� : " << donation << " ��\n";
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
