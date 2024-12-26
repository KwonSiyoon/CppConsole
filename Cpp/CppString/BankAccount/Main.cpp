#include <iostream>

class Account {
public:
	Account(int id, const char* name, int balance)
		: id(id), balance(balance)
	{
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}
	void Deposit(int balance)
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
	void Withdraw(int balance)
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
				std::cout << "�ܾ� : " << this->balance <<"\n";
			}
		}
	}
	void Print()
	{
		std::cout << "���¹�ȣ : " << id << "  �̸� : " << name << "  �ܾ� : " << balance << "\n";
	}
private:
	int id;			// ���¹�ȣ
	char* name;		// �̸�
	int balance;	// �ܾ�
};

class Bank {
public:
	void CreateAccount(const char* name, int balance)
	{
		accounts[lastNum] = new Account(lastNum, name, balance);
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
	}
	void Withdraw(int id, int balance)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "���� ���¹�ȣ�Դϴ�.\n";
			return;
		}
		accounts[id]->Withdraw(balance);
	}
	void Inquire()
	{
		for (Account* account : accounts)
		{
			account->Print();
		}
	}
private:
	Account* accounts[100];
	int lastNum = 0;
};

void Loop()
{
	Bank bank;
	char input;
	char* name = new char[100];
	int id;
	int balance;
	while (true)
	{
		std::cout << "1. ���� ����  2. �Ա�  3. ���  4. ��ü �� �ܾ� ��ȸ\n";
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
			bank.Deposit(id, balance);
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
}


int main() {
	Loop();

	std::cin.get();
	return 0;
}