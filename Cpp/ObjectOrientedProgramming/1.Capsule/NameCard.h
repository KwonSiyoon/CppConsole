#pragma once
#include <string>
#include <iostream>

class NameCard
{
public:

    NameCard(const std::string& name, const std::string& phoneNumber, const std::string& address, const std::string& rank)
        : name(name), phoneNumber(phoneNumber), address(address), rank(rank)
    {

    }
    void ShowData()
    {
        std::cout << "이    름: " << name << "\n전화번호: " << phoneNumber << "\n주    소: " << address << "\n직    급: " << rank << "\n";
    }
private:
    std::string name;
    std::string phoneNumber;
    std::string address;
    std::string rank;
};