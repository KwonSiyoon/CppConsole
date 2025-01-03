#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include <iostream>


Account::Account()
	: Account(id, name, balance)
{
}

Account::Account(int id, const char* name, int money)
	: id(id), balance(money), highCredit(false)
{
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::Account(const Account& account)
{
	id = account.id;
	balance = account.balance;
	highCredit = account.highCredit;

	// 깊은복사
	size_t length = strlen(account.name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, account.name);
}

Account::~Account()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (creditAccount != nullptr)
	{
		delete creditAccount;
	}
	if (donationAccount != nullptr)
	{
		delete donationAccount;
	}
}

void Account::Deposit(int money)
{
	if (money <= 0)
	{
		std::cout << "0이상의 숫자를 입력하세요.\n";
		int num;
		std::cin >> num;
		Deposit(num);
	}
	else
	{
		this->balance += money;
		if (highCredit)
		{
			if (creditAccount == nullptr)
			{
				creditAccount = new CreditAccount();
			}
		}
	}
}

void Account::Withdraw(int money)
{
	if (money <= 0)
	{
		std::cout << "0이상의 숫자를 입력하세요.\n";
		int num;
		std::cin >> num;
		Withdraw(num);
	}
	else
	{
		if (money > this->balance)
		{
			std::cout << "잔액이 부족합니다.\n";
		}
		else
		{
			this->balance -= money;
			std::cout << "잔액 : " << this->balance << "\n";
		}
	}
}

void Account::Print()
{
	std::cout << "계좌번호 : " << id << "  이름 : " << name << "  잔액 : " << balance << "\n";
	if (creditAccount)
	{
		creditAccount->Print();
	}
	if (donationAccount)
	{
		donationAccount->Print();
	}
}
