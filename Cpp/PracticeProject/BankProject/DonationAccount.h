#pragma once

class DonationAccount : public Account
{
public:
	DonationAccount();
	~DonationAccount();
	virtual void Deposit(int money) override;
	virtual void Withdraw(int money) override;
	virtual void Print() override;
private:
	int donation;
	const float donationRate = 0.01f;
};

