#pragma once
class CreditAccount;
class DonationAccount;
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
private:
	int balance;		// �ܾ�
	bool highCredit;	// �ſ� ��� ����.
	CreditAccount* creditAccount = nullptr;
	DonationAccount* donationAccount = nullptr;
};

