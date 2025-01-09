#pragma once

enum class ACCOUNT_TYPE
{
	ACCOUNT = 0,
	CREDIT_ACCOUNT,
	DONATION_ACCOUNT
};


class DonationAccount;
class CreditAccount;
class Account;
class Bank
{
public:
	Bank();
	~Bank();
	void CreateAccount(const char* name, int money, ACCOUNT_TYPE type);
	void Deposit(int id, int money, ACCOUNT_TYPE type);
	void Withdraw(int id, int money, ACCOUNT_TYPE type);
	void Inquire(ACCOUNT_TYPE type);
	Account** GetAccounts();
private:
	class Account* accounts[100]{};
	class CreditAccount* creditAccounts[100]{};
	class DonationAccount* donationAccounts[100]{};
	int accountsNum = 0;
	int creditAccountsNum = 0;
	int donationAccountsNum = 0;
};

