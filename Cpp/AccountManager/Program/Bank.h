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
	Account* accounts[100]{};									// ���� ���� ������ ���� �迭.

	int count;												// ����� ������ ��.
};

