#include "Account.h"

Account::Account()
    : Account(0, nullptr, 0)
{
}

Account::Account(int id, const char* name, int balance)
    : id(id), balance(balance), name(nullptr)
{
    if (name != nullptr)
    {
        size_t length = strlen(name) + 1;
        this->name = new char[length];
        strcpy_s(this->name, length, name);
    }
    else
    {
        this->name = nullptr;
    }
}

Account::~Account()
{
    delete[] name;
}

void Account::Deposit(int money)
{
    if (money <= 0)
    {
        std::cout << "�Աݾ��� 0���� Ŀ���մϴ�.\n";
        return;
    }

    // �ܾ׿� �߰�.
    balance += money;
}

void Account::Withdraw(int money)
{
    if (money <= 0)
    {
        std::cout << "��ݾ��� 0���� Ŀ���մϴ�.\n";
        return;
    }
    // �ܾ׿��� ����.
    balance -= money;
}

void Account::Print()
{
    std::cout << "���� ID: " << id << " | ";
    std::cout << "�̸�: " << name << " | ";
    std::cout << "�ܾ�: " << balance << "\n";
}

int Account::GetID() const
{
    return 0;
}

const char* Account::GetName() const
{
    return nullptr;
}

int Account::GetBalance() const
{
    return 0;
}
