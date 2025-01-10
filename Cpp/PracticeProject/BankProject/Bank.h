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
	const char* SAVE_FORMAT = "type: %d id: %d name: %s balance: %d other: %d\n";
	const char* LOAD_FORMAT = "type: %d id: %d name: %s balance: %d other: %d";
	const char* ACCOUNT_INFO = "AccountInfo.txt";
public:
	Bank();
	~Bank();
	void SaveToFile(const char* filename);    // 계좌 정보 저장
	void LoadFromFile(const char* filename);  // 계좌 정보 불러오기
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

