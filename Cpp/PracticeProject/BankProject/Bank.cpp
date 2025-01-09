#include "Bank.h"
#include "Account.h"
#include "DonationAccount.h"
#include "CreditAccount.h"
#include <iostream>

Bank::Bank()
{
}

Bank::~Bank()
{
	for (Account* account : accounts)
	{
		if (account != nullptr)
		{
			delete account;
			account = nullptr;
		}
	}
}

void Bank::CreateAccount(const char* name, int money, ACCOUNT_TYPE type)
{
	if (type == ACCOUNT_TYPE::ACCOUNT)
	{
		accounts[accountsNum] = new Account(accountsNum, name, money);
		accounts[accountsNum]->Print();
		++accountsNum;
	}
	else if (type == ACCOUNT_TYPE::CREDIT_ACCOUNT)
	{
		creditAccounts[creditAccountsNum] = new CreditAccount(creditAccountsNum, name, money);
		creditAccounts[creditAccountsNum]->Print();
		++creditAccountsNum;
	}
	else if (type == ACCOUNT_TYPE::DONATION_ACCOUNT)
	{
		donationAccounts[donationAccountsNum] = new DonationAccount(donationAccountsNum, name, money);
		donationAccounts[donationAccountsNum]->Print();
		++donationAccountsNum;
	}
	std::cout << "계좌가 개설되었습니다.\n";
}

void Bank::Deposit(int id, int money, ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		if (accounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		accounts[id]->Deposit(money);
		accounts[id]->Print();
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		if (creditAccounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		creditAccounts[id]->Deposit(money);
		creditAccounts[id]->Print();
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		if (donationAccounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		donationAccounts[id]->Deposit(money);
		donationAccounts[id]->Print();
		break;
	default:
		break;
	}
	
}

void Bank::Withdraw(int id, int money, ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		if (accounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		accounts[id]->Withdraw(money);
		accounts[id]->Print();
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		if (creditAccounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		creditAccounts[id]->Withdraw(money);
		creditAccounts[id]->Print();
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		if (donationAccounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		donationAccounts[id]->Withdraw(money);
		donationAccounts[id]->Print();
		break;
	default:
		break;
	}
	
}

void Bank::Inquire(ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		for (Account* account : accounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		for (Account* account : creditAccounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		for (Account* account : donationAccounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	default:
		break;
	}
	
}

Account** Bank::GetAccounts()
{
	return accounts;
}
