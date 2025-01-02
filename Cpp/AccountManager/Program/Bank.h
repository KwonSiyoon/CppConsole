#pragma once
#include <iostream>
class Account;
class Bank
{
public:
	Bank();
	~Bank();
	void PrintMenu();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void Inquire();
private:
	Account* accounts[100]{};									// 계좌 정보 저장을 위한 배열.

	int count;												// 저장된 계좌의 수.
};

