#pragma once
class Account;
class Bank
{
public:
	Bank();
	~Bank();
	void CreateAccount(const char* name, int money);
	void Deposit(int id, int money);
	void Withdraw(int id, int money);
	void Inquire();
private:
	class Account* accounts[100]{};
	class CreditAccount* creditAccounts[100]{};
	class DonationAccount* donationAccounts[100]{};
	int lastNum = 0;
};

