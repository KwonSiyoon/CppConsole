#pragma once

#include <iostream>

// ���� �����غ��� ���ڿ� Ŭ����.
// MFC - UI.
class String
{
public:
	
	String(const char* string = nullptr);											// �Ϲ� ������.
	String(const String& other);													// ���� ������.
	~String();																		// �Ҹ���.
	friend std::ostream& operator<<(std::ostream& os, const String& string);		// ������ �����ε�.   // ���� �Լ� ���(friend �ʿ�).
	String& operator=(const String& other);											// ���� ������.		 // ��� �Լ� ���.
	bool operator==(const String& other);											// �� ������.
	bool operator!=(const String& other);											// �� ������.

	// Getter.
	const int Length() const;
	const char* Data() const;

private:
	int length;				// ���ڿ� ����.
	char* data;				// ���ڿ� �����ϴ� ����(�����/�����̳�/container).
};

