#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include <iostream>


Account::Account()
	: Account(0, nullptr, 0)
{
}

Account::Account(int id, const char* name, int money)
	: id(id), balance(money), name(nullptr)
{
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::Account(const Account& account)
{
	id = account.id;
	balance = account.balance;

	// ��������
	size_t length = strlen(account.name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, account.name);
}

Account::~Account()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Account::Deposit(int money)
{
	if (money <= 0)
	{
		std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
		int num;
		std::cin >> num;
		Deposit(num);
	}
	else
	{
		this->balance += money;
	}
}

void Account::Withdraw(int money)
{
	if (money <= 0)
	{
		std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
		int num;
		std::cin >> num;
		Withdraw(num);
	}
	else
	{
		if (money > this->balance)
		{
			std::cout << "�ܾ��� �����մϴ�.\n";
		}
		else
		{
			this->balance -= money;
			std::cout << "�ܾ� : " << this->balance << "\n";
		}
	}
}

void Account::Print()
{
	std::cout << "���¹�ȣ : " << id << "  �̸� : " << name << "  �ܾ� : " << balance << "\n";
}

const int Account::GetID()
{
	return id;
}

const char* Account::GetName()
{
	return name;
}

const int Account::GetBalance()
{
	return balance;
}
