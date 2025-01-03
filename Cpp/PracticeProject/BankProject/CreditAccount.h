#pragma once

class CreditAccount : public Account
{
public:
	CreditAccount();
	~CreditAccount();
	virtual void Deposit(int money) override;
	virtual void Withdraw(int money) override;
	virtual void Print() override;
private:
	int interest;
	const float interestRate = 0.01f;
};

