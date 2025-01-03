#pragma once
class CreditAccount;
class DonationAccount;
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
protected:
	int id;				// 계좌번호
	char* name{};		// 이름
private:
	int balance;		// 잔액
	bool highCredit;	// 신용 등급 만족.
	CreditAccount* creditAccount = nullptr;
	DonationAccount* donationAccount = nullptr;
};

