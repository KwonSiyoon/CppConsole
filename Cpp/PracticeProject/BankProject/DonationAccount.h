#pragma once

class DonationAccount : public Account
{
public:
	DonationAccount();
	DonationAccount(int id, const char* name, int money);
	virtual ~DonationAccount() override;
	virtual void Deposit(int money) override;
	virtual void Withdraw(int money) override;
	virtual void Print() override;
private:
	int donation;
	const float donationRate = 0.01f;
};

