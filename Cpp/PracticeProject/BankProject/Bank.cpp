#include "Bank.h"
#include "Account.h"


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
		}
	}
}

void Bank::CreateAccount(const char* name, float money)
{
	accounts[lastNum] = new Account(lastNum, name, money);
	accounts[lastNum]->Print();
	std::cout << "계좌가 개설되었습니다.\n";
	++lastNum;
}

void Bank::Deposit(int id, float money)
{
	if (accounts[id] == nullptr)
	{
		std::cout << "없는 계좌번호입니다.\n";
		return;
	}
	accounts[id]->Deposit(money);
	accounts[id]->Print();
}

void Bank::Withdraw(int id, float money)
{
	if (accounts[id] == nullptr)
	{
		std::cout << "없는 계좌번호입니다.\n";
		return;
	}
	accounts[id]->Withdraw(money);
	accounts[id]->Print();
}

void Bank::Inquire()
{
	for (Account* account : accounts)
	{
		if (account == nullptr) continue;
		account->Print();
	}
}
