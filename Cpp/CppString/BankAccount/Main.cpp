#include <iostream>

class Account
{
public:
	Account(int id, const char* name, int money)
		: id(id), balance(money)
	{
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}
	Account(const Account& account) // ���������.
	{
		id = account.id;
		balance = account.balance;

		// ��������
		size_t length = strlen(account.name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, account.name);
	}
	virtual ~Account()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		if (creditAccount != nullptr)
		{
			delete creditAccount;
		}
		if (donationAccount != nullptr)
		{
			delete donationAccount;
		}
	}
	virtual void Deposit(float money)
	{
		if (money <= 0)
		{
			std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
			int num;
			std::cin >> num;
			Deposit(num);
		}
		else
		{
			this->balance += money;
		}
	}
	virtual void Withdraw(int money)
	{
		if (money <= 0)
		{
			std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
			int num;
			std::cin >> num;
			Withdraw(num);
		}
		else
		{
			if (money > this->balance)
			{
				std::cout << "�ܾ��� �����մϴ�.\n";
			}
			else
			{
				this->balance -= money;
				std::cout << "�ܾ� : " << this->balance << "\n";
			}
		}
	}
	virtual void Print()
	{
		std::cout << "���¹�ȣ : " << id << "  �̸� : " << name << "  �ܾ� : " << balance << "\n";
		if (creditAccount)
		{

		}
		if (donationAccount)
		{

		}
	}
private:
	int id;				// ���¹�ȣ
	char* name{};		// �̸�
	float balance;		// �ܾ�
	bool highCredit;	// �ſ� ��� ����.
	CreditAccount* creditAccount{};
	DonationAccount* donationAccount{};
};

class CreditAccount : public Account
{
public:
	CreditAccount();
	~CreditAccount();
	
	virtual void Deposit(float money) override
	{
		interest += money * interestRate;
	}
	virtual void Withdraw(int money) override
	{

	}
	virtual void Print() override
	{

	}
private:
	float interest;
	float interestRate = 0.01f;
};

class DonationAccount : public Account
{
public:
	DonationAccount();
	~DonationAccount();
	virtual void Deposit(float money) override
	{
		donation += money * donationRate;
	}
	virtual void Withdraw(int money) override
	{

	}
	virtual void Print() override
	{
		
	}
private:
	float donation;
	float donationRate = 0.01f;
};

class Bank
{
public:
	~Bank()
	{
		for (Account* account : accounts)
		{
			if (account != nullptr)
			{
				delete account;
			}
		}
	}
	void CreateAccount(const char* name, float money)
	{
		accounts[lastNum] = new Account(lastNum, name, money);
		accounts[lastNum]->Print();
		std::cout << "���°� �����Ǿ����ϴ�.\n";
		++lastNum;
	}
	void Deposit(int id, float money)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Deposit(money);
		accounts[id]->Print();
	}
	void Withdraw(int id, float money)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Withdraw(money);
		accounts[id]->Print();
	}
	void Inquire()
	{
		for (Account* account : accounts)
		{
			if (account == nullptr) continue;
			account->Print();
		}
	}
private:
	class Account* accounts[100]{};
	//class CreditAccount* creditAccounts[100]{};
	//class DonationAccount* donationAccounts[100]{};
	int lastNum = 0;
};

void Loop()
{
	Bank bank;
	char input;
	char* name{};
	int id;
	int money;
	while (true)
	{
		std::cout << "1.���� ����  2.�Ա�  3.���  4.��ü �� �ܾ� ��ȸ\n";
		std::cin >> input;
		if (input == 'q' || input == 'Q')
		{
			break;
		}
		if (input == '1')				// ���� ����
		{
			std::cout << "�̸��� �Է����ּ���.\n";
			std::cin >> name;
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.CreateAccount(name, money);
		}
		else if (input == '2')			// �Ա�
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.Deposit(id, money);
		}
		else if (input == '3')			// ���
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "����� �ݾ��� �Է����ּ���.\n";
			std::cin >> money;
			bank.Withdraw(id, money);
		}
		else if (input == '4')			// ��ü �� �ܾ� ��ȸ
		{
			bank.Inquire();
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���.\n";
		}
	}
	if (name != nullptr)
	{
		delete[] name;
	}
}


int main()
{
	Loop();

	std::cin.get();
	return 0;
}