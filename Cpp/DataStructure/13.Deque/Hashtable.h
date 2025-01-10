#pragma once

#include <string>
#include <vector>
#include "Pair.h"

class Hashtable
{
private:
	// Alias(별칭) 선언.
	using Entry = Pair<std::string, std::string>;

public:
	// 명시적으로 기본 생성자 선언.
	Hashtable() = default;
	// 명시적으로 기본 소멸자 선언.
	~Hashtable() = default;

	bool IsEmpty() const;
	void Add(const std::string& key, const std::string& value);
	void Delete(const std::string& key);
	bool Find(const std::string& key, Entry& outValue);
	void Print();

private:

	static const int bucketCount = 19;
	std::vector<Entry> table[bucketCount];
};