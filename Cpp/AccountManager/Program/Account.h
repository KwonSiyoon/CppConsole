#pragma once
#include <iostream>
class Account
{
public:
	Account();
	Account(int id, const char* name, int balance);
	~Account();
	void Deposit(int money);
	void Withdraw(int money);
	void Print();
	int GetID()	const;
	const char* GetName() const;
	int GetBalance() const;

private:
	int id;											// ID
	char* name;										// ÀÌ¸§
	int balance;									// ÀÜ¾×.
};

