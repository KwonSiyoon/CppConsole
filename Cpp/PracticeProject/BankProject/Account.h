#pragma once
#include <iostream>
class CreditAccount;
class DonationAccount;
class Account
{
public:
	Account(int id, const char* name, int money);
	Account(const Account& account); // ���������.
	virtual ~Account();
	virtual void Deposit(float money);
	virtual void Withdraw(int money);
	virtual void Print();
private:
	int id;				// ���¹�ȣ
	char* name{};		// �̸�
	float balance;		// �ܾ�
	bool highCredit;	// �ſ� ��� ����.
	CreditAccount* creditAccount{};
	DonationAccount* donationAccount{};
};

