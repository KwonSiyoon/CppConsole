#pragma once

#include <string>

// 추상 클래스 (인터페이스).
class INamedPerson
{
public:
    // 순수 가상 함수(추상 함수).
    virtual std::string GetName() const = 0;

private:


};