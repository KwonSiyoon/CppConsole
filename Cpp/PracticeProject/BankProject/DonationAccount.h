#pragma once
#include "Account.h"
class DonationAccount : public Account
{
public:
	DonationAccount();
	~DonationAccount();
	virtual void Deposit(float money) override;
	virtual void Withdraw(int money) override;
	virtual void Print() override;
private:
	float donation;
	const float donationRate = 0.01f;
};

