#pragma once

class Account
{
public:
	Account();
	Account(int id, const char* name, int money);
	Account(const Account& account); // ���������.
	virtual ~Account();
	virtual void Deposit(int money);
	virtual void Withdraw(int money);
	virtual void Print();
protected:
	int id;				// ���¹�ȣ
	char* name{};		// �̸�
	int balance;		// �ܾ�
};

