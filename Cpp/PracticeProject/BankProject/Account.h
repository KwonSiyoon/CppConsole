#pragma once

class Account
{
public:
	Account();
	Account(int id, const char* name, int money);
	Account(const Account& account); // 복사생성자.
	virtual ~Account();
	virtual void Deposit(int money);
	virtual void Withdraw(int money);
	virtual void Print();
	virtual const int GetID();
	virtual const char* GetName();
	virtual const int GetBalance();
protected:
	int id;				// 계좌번호
	char* name{};		// 이름
	int balance;		// 잔액
};

