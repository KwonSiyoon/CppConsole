#include "Bank.h"
#include "Account.h"
#include "DonationAccount.h"
#include "CreditAccount.h"
#include <iostream>

Bank::Bank()
{
	LoadFromFile(ACCOUNT_INFO);
}

Bank::~Bank()
{
	SaveToFile(ACCOUNT_INFO);
	for (Account* account : accounts)
	{
		if (account != nullptr)
		{
			delete account;
			account = nullptr;
		}
	}
}

void Bank::SaveToFile(const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");

	if (file != nullptr)
	{
		// �Ϲ� ���� ����
		for (int i = 0; i < accountsNum; i++)
		{
			char data[1024] = {};
			snprintf(data, 1024, SAVE_FORMAT,
				static_cast<int>(ACCOUNT_TYPE::ACCOUNT),
				accounts[i]->GetID(),
				accounts[i]->GetName(),
				accounts[i]->GetBalance(),
				0);

			size_t length = strlen(data);
			fwrite(data, length, 1, file);
		}

		// �ſ� ���� ����
		for (int i = 0; i < creditAccountsNum; i++)
		{
			char data[1024] = {};
			snprintf(data, 1024, SAVE_FORMAT,
				static_cast<int>(ACCOUNT_TYPE::CREDIT_ACCOUNT),
				creditAccounts[i]->GetID(),
				creditAccounts[i]->GetName(),
				creditAccounts[i]->GetBalance(),
				creditAccounts[i]->GetInterest());

			size_t length = strlen(data);
			fwrite(data, length, 1, file);
		}

		// ��� ���� ����
		for (int i = 0; i < donationAccountsNum; i++)
		{
			char data[1024] = {};
			snprintf(data, 1024, SAVE_FORMAT,
				static_cast<int>(ACCOUNT_TYPE::DONATION_ACCOUNT),
				donationAccounts[i]->GetID(),
				donationAccounts[i]->GetName(),
				donationAccounts[i]->GetBalance(),
				donationAccounts[i]->GetDonation());

			size_t length = strlen(data);
			fwrite(data, length, 1, file);
		}
		fclose(file);
	}
}

void Bank::LoadFromFile(const char* filename)
{
	// ���� ���µ� ����
	for (int i = 0; i < accountsNum; i++)
	{
		delete accounts[i];
		accounts[i] = nullptr;
	}
	for (int i = 0; i < creditAccountsNum; i++)
	{
		delete creditAccounts[i];
		creditAccounts[i] = nullptr;
	}
	for (int i = 0; i < donationAccountsNum; i++)
	{
		delete donationAccounts[i];
		donationAccounts[i] = nullptr;
	}
	accountsNum = 0;
	creditAccountsNum = 0;
	donationAccountsNum = 0;

	FILE* file = nullptr;
	fopen_s(&file, filename, "rb");

	if (file != nullptr)
	{
		char buffer[1024];

		while (!feof(file))
		{
			if (fgets(buffer, 1024, file) != nullptr)
			{
				char namebuffer[256];
				int type, id, balance;

				if (sscanf_s(buffer,
					LOAD_FORMAT,
					&type, &id, namebuffer, 256, &balance) == 4)
				{

					// ���� Ÿ�Կ� ���� ������ �迭�� �߰�
					switch (static_cast<ACCOUNT_TYPE>(type))
					{
					case ACCOUNT_TYPE::ACCOUNT:
						if (accountsNum < 100)
						{
							accounts[accountsNum] = new Account(id, namebuffer, balance);
							accountsNum++;
						}
						break;

					case ACCOUNT_TYPE::CREDIT_ACCOUNT:
						if (creditAccountsNum < 100)
						{
							creditAccounts[creditAccountsNum] = new CreditAccount(id, namebuffer, balance);
							creditAccountsNum++;
						}
						break;

					case ACCOUNT_TYPE::DONATION_ACCOUNT:
						if (donationAccountsNum < 100)
						{
							donationAccounts[donationAccountsNum] = new DonationAccount(id, namebuffer, balance);
							donationAccountsNum++;
						}
						break;
					}
				}
			}
		}
		fclose(file);
		std::cout << "�Ϲ� ����: " << accountsNum << "��\n";
		std::cout << "�ſ� ����: " << creditAccountsNum << "��\n";
		std::cout << "��� ����: " << donationAccountsNum << "���� �ҷ��Խ��ϴ�.\n";
	}
	else
	{
		std::cout << "������ �� �� �����ϴ�." << std::endl;
	}
}

void Bank::CreateAccount(const char* name, int money, ACCOUNT_TYPE type)
{
	if (type == ACCOUNT_TYPE::ACCOUNT)
	{
		accounts[accountsNum] = new Account(accountsNum, name, money);
		accounts[accountsNum]->Print();
		++accountsNum;
	}
	else if (type == ACCOUNT_TYPE::CREDIT_ACCOUNT)
	{
		creditAccounts[creditAccountsNum] = new CreditAccount(creditAccountsNum, name, money);
		creditAccounts[creditAccountsNum]->Print();
		++creditAccountsNum;
	}
	else if (type == ACCOUNT_TYPE::DONATION_ACCOUNT)
	{
		donationAccounts[donationAccountsNum] = new DonationAccount(donationAccountsNum, name, money);
		donationAccounts[donationAccountsNum]->Print();
		++donationAccountsNum;
	}
	std::cout << "���°� �����Ǿ����ϴ�.\n";
}

void Bank::Deposit(int id, int money, ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Deposit(money);
		accounts[id]->Print();
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		if (creditAccounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		creditAccounts[id]->Deposit(money);
		creditAccounts[id]->Print();
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		if (donationAccounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		donationAccounts[id]->Deposit(money);
		donationAccounts[id]->Print();
		break;
	default:
		break;
	}
	
}

void Bank::Withdraw(int id, int money, ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Withdraw(money);
		accounts[id]->Print();
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		if (creditAccounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		creditAccounts[id]->Withdraw(money);
		creditAccounts[id]->Print();
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		if (donationAccounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		donationAccounts[id]->Withdraw(money);
		donationAccounts[id]->Print();
		break;
	default:
		break;
	}
	
}

void Bank::Inquire(ACCOUNT_TYPE type)
{
	switch (type)
	{
	case ACCOUNT_TYPE::ACCOUNT:
		for (Account* account : accounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	case ACCOUNT_TYPE::CREDIT_ACCOUNT:
		for (Account* account : creditAccounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	case ACCOUNT_TYPE::DONATION_ACCOUNT:
		for (Account* account : donationAccounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
		break;
	default:
		break;
	}
	
}

Account** Bank::GetAccounts()
{
	return accounts;
}
