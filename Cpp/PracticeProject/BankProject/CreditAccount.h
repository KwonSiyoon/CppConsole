#pragma once

class CreditAccount : public Account
{
public:
	CreditAccount();
	CreditAccount(int id, const char* name, int money);
	virtual ~CreditAccount() override;
	virtual void Deposit(int money) override;
	virtual void Withdraw(int money) override;
	virtual void Print() override;
	virtual const int GetID() override;
	virtual const char* GetName() override;
	virtual const int GetBalance() override;
	virtual const int GetInterest();
private:
	int interest;
	const float interestRate = 0.01f;
};

