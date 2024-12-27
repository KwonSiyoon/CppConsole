#include <iostream>

class Account
{
public:
	Account(int id, const char* name, int balance)
		: id(id), balance(balance)
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
	}
	virtual void Deposit(int balance)
	{
		if (balance <= 0)
		{
			std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
			int num;
			std::cin >> num;
			Deposit(num);
		}
		else
		{
			this->balance += balance;
		}
	}
	virtual void Withdraw(int balance)
	{
		if (balance <= 0)
		{
			std::cout << "0�̻��� ���ڸ� �Է��ϼ���.\n";
			int num;
			std::cin >> num;
			Withdraw(num);
		}
		else
		{
			if (balance > this->balance)
			{
				std::cout << "�ܾ��� �����մϴ�.\n";
			}
			else
			{
				this->balance -= balance;
				std::cout << "�ܾ� : " << this->balance << "\n";
			}
		}
	}
	virtual void Print()
	{
		std::cout << "���¹�ȣ : " << id << "  �̸� : " << name << "  �ܾ� : " << balance << "\n";
	}
private:
	int id;				// ���¹�ȣ
	char* name{};		// �̸�
	int balance;		// �ܾ�
};

class CreditAccount : public Account
{
public:
	virtual void Deposit(int balance) override
	{

	}
	virtual void Withdraw(int balance) override
	{

	}
	virtual void Print() override
	{

	}

};

class DonationAccount : public Account
{
public:
	virtual void Deposit(int balance) override
	{

	}
	virtual void Withdraw(int balance) override
	{

	}
	virtual void Print() override
	{

	}
private:
	int donation;
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
	void CreateAccount(const char* name, int balance)
	{
		accounts[lastNum] = new Account(lastNum, name, balance);
		accounts[lastNum]->Print();
		std::cout << "���°� �����Ǿ����ϴ�.\n";
		++lastNum;
	}
	void Deposit(int id, int balance)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Deposit(balance);
		accounts[id]->Print();
	}
	void Withdraw(int id, int balance)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Withdraw(balance);
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
	class CreditAccount* creditAccounts[100]{};
	class DonationAccount* donationAccounts[100]{};
	int lastNum = 0;
};

void Loop()
{
	Bank bank;
	char input;
	char* name{};
	int id;
	int balance;
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
			std::cin >> balance;
			bank.CreateAccount(name, balance);
		}
		else if (input == '2')			// �Ա�
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
			std::cin >> balance;
			bank.Deposit(id, balance);
		}
		else if (input == '3')			// ���
		{
			std::cout << "���¹�ȣ�� �Է����ּ���.\n";
			std::cin >> id;
			std::cout << "����� �ݾ��� �Է����ּ���.\n";
			std::cin >> balance;
			bank.Withdraw(id, balance);
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