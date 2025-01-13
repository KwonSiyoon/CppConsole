#pragma once

#include <iostream>

class String
{
public:
    String(const char* value = nullptr);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String& operator+=(const String& other);
    bool operator==(const String& other);
    String operator+(const String& other);

    friend std::ostream& operator<<(std::ostream& outStream, const String& other);
    friend std::istream& operator>>(std::istream& inStream, String& other);

private:
    int length;			// null 문자를 포함하는 문자열의 길이.
    char* data;			// 문자열을 저장할 변수.
};