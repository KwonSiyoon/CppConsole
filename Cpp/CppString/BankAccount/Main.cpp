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
			std::cout << "0이상의 숫자를 입력하세요.\n";
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
			std::cout << "0이상의 숫자를 입력하세요.\n";
			int num;
			std::cin >> num;
			Withdraw(num);
		}
		else
		{
			if (balance > this->balance)
			{
				std::cout << "잔액이 부족합니다.\n";
			}
			else
			{
				this->balance -= balance;
				std::cout << "잔액 : " << this->balance <<"\n";
			}
		}
	}
	void Print()
	{
		std::cout << "계좌번호 : " << id << "  이름 : " << name << "  잔액 : " << balance << "\n";
	}
private:
	int id;			// 계좌번호
	char* name;		// 이름
	int balance;	// 잔액
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
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		accounts[id]->Deposit(balance);
	}
	void Withdraw(int id, int balance)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
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
		std::cout << "1. 계좌 개설  2. 입금  3. 출금  4. 전체 고객 잔액 조회\n";
		std::cin >> input;
		if (input == 'q' || input == 'Q')
		{
			break;
		}
		if (input == '1')				// 계좌 개설
		{
			std::cout << "이름을 입력해주세요.\n";
			std::cin >> name;
			std::cout << "입금할 금액을 입력해주세요.\n";
			std::cin >> balance;
			bank.CreateAccount(name, balance);
		}
		else if (input == '2')			// 입금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "입금할 금액을 입력해주세요.\n";
			std::cin >> balance;
			bank.Deposit(id, balance);
		}
		else if (input == '3')			// 출금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "출금할 금액을 입력해주세요.\n";
			std::cin >> balance;
			bank.Deposit(id, balance);
		}
		else if (input == '4')			// 전체 고객 잔액 조회
		{
			bank.Inquire();
		}
		else
		{
			std::cout << "다시 입력해주세요.\n";
		}
	}
}


int main() {
	Loop();

	std::cin.get();
	return 0;
}