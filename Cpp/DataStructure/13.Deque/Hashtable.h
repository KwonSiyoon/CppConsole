#pragma once

#include <string>
#include <vector>
#include "Pair.h"

class Hashtable
{
private:
	// Alias(��Ī) ����.
	using Entry = Pair<std::string, std::string>;

public:
	// ��������� �⺻ ������ ����.
	Hashtable() = default;
	// ��������� �⺻ �Ҹ��� ����.
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