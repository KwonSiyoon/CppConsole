#pragma once
class Account;
class Bank
{
public:
	Bank();
	~Bank();
	void CreateAccount(const char* name, float money);
	void Deposit(int id, float money);
	void Withdraw(int id, float money);
	void Inquire();
private:
	class Account* accounts[100]{};
	class CreditAccount* creditAccounts[100]{};
	class DonationAccount* donationAccounts[100]{};
	int lastNum = 0;
};

