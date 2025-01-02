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
	Account(const Account& account) // 복사생성자.
	{
		id = account.id;
		balance = account.balance;

		// 깊은복사
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
			std::cout << "0이상의 숫자를 입력하세요.\n";
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
			std::cout << "0이상의 숫자를 입력하세요.\n";
			int num;
			std::cin >> num;
			Withdraw(num);
		}
		else
		{
			if (money > this->balance)
			{
				std::cout << "잔액이 부족합니다.\n";
			}
			else
			{
				this->balance -= money;
				std::cout << "잔액 : " << this->balance << "\n";
			}
		}
	}
	virtual void Print()
	{
		std::cout << "계좌번호 : " << id << "  이름 : " << name << "  잔액 : " << balance << "\n";
		if (creditAccount)
		{

		}
		if (donationAccount)
		{

		}
	}
private:
	int id;				// 계좌번호
	char* name{};		// 이름
	float balance;		// 잔액
	bool highCredit;	// 신용 등급 만족.
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
		std::cout << "계좌가 개설되었습니다.\n";
		++lastNum;
	}
	void Deposit(int id, float money)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
			return;
		}
		accounts[id]->Deposit(money);
		accounts[id]->Print();
	}
	void Withdraw(int id, float money)
	{
		if (accounts[id] == nullptr)
		{
			std::cout << "없는 계좌번호입니다.\n";
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
		std::cout << "1.계좌 개설  2.입금  3.출금  4.전체 고객 잔액 조회\n";
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
			std::cin >> money;
			bank.CreateAccount(name, money);
		}
		else if (input == '2')			// 입금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "입금할 금액을 입력해주세요.\n";
			std::cin >> money;
			bank.Deposit(id, money);
		}
		else if (input == '3')			// 출금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "출금할 금액을 입력해주세요.\n";
			std::cin >> money;
			bank.Withdraw(id, money);
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