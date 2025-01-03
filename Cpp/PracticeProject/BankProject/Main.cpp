#include <iostream>
#include "Bank.h"

void Loop()
{
	Bank bank;
	char input;
	char* name{};
	int id;
	int money;
	ACCOUNT_TYPE type;
	while (true)
	{
		std::cout << "1. 일반 계좌  2. 신용 계좌  3. 기부 계좌\n";
		std::cin >> input;
		while (true)
		{
			if (input == '1')
			{
				type = ACCOUNT_TYPE::ACCOUNT;
				break;
			}
			else if (input == '2')
			{
				type = ACCOUNT_TYPE::CREDIT_ACCOUNT;
				break;
			}
			else if (input == '3')
			{
				type = ACCOUNT_TYPE::DONATION_ACCOUNT;
				break;
			}
			else
			{
				std::cout << "다시 입력해주세요.\n";
				std::cout << "1. 일반 계좌  2. 신용 계좌  3. 기부 계좌\n";
			}
		}
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
			bank.CreateAccount(name, money, type);
		}
		else if (input == '2')			// 입금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "입금할 금액을 입력해주세요.\n";
			std::cin >> money;
			bank.Deposit(id, money, type);
		}
		else if (input == '3')			// 출금
		{
			std::cout << "계좌번호를 입력해주세요.\n";
			std::cin >> id;
			std::cout << "출금할 금액을 입력해주세요.\n";
			std::cin >> money;
			bank.Withdraw(id, money, type);
		}
		else if (input == '4')			// 전체 고객 잔액 조회
		{
			bank.Inquire(type);
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