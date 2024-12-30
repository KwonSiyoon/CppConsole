#pragma once

#include <iostream>

// 직접 구현해보는 문자열 클래스.
// MFC - UI.
class String
{
public:
	
	String(const char* string = nullptr);											// 일반 생성자.
	String(const String& other);													// 복사 생성자.
	~String();																		// 소멸자.
	friend std::ostream& operator<<(std::ostream& os, const String& string);		// 연산자 오버로딩.   // 비멤버 함수 방식(friend 필요).
	String& operator=(const String& other);											// 대입 연산자.		 // 멤버 함수 방식.
	bool operator==(const String& other);											// 비교 연산자.
	bool operator!=(const String& other);											// 비교 연산자.

	// Getter.
	const int Length() const;
	const char* Data() const;

private:
	int length;				// 문자열 길이.
	char* data;				// 문자열 저장하는 변수(저장소/컨테이너/container).
};

