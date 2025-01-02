#pragma once
#include <iostream>
class CreditAccount;
class DonationAccount;
class Account
{
public:
	Account(int id, const char* name, int money);
	Account(const Account& account); // 복사생성자.
	virtual ~Account();
	virtual void Deposit(float money);
	virtual void Withdraw(int money);
	virtual void Print();
private:
	int id;				// 계좌번호
	char* name{};		// 이름
	float balance;		// 잔액
	bool highCredit;	// 신용 등급 만족.
	CreditAccount* creditAccount{};
	DonationAccount* donationAccount{};
};

