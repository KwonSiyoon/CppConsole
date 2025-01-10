#include "Hashtable.h"
#include <iostream>

int GenerateKey(const std::string& keyString)
{
	int key = 0;
	for (int ix = 0; ix < (int)keyString.size(); ++ix)
	{
		//key += keyString[ix] * (ix + 1);

		key = key * 31 + keyString[ix];
	}

	// 해시 값이 너무 크면 음수가 반환되는 경우가 있어서 양수로 만듬.
	//return std::abs(key);
	return key < 0 ? -key : key;
}


bool Hashtable::IsEmpty() const
{
	size_t sum = 0;
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		sum += table[ix].size();
	}

	return sum == 0;
}

void Hashtable::Add(const std::string& key, const std::string& value)
{
	int bucketIndex = GenerateKey(key) % bucketCount;

	std::vector<Entry>& position = table[bucketIndex];

	for (int ix = 0; ix < (int)position.size(); ++ix)
	{
		if (position[ix].key == key)
		{
			std::cout << "이미 동일한 데이터가 저장돼 있습니다.\n";
			return;
		}
	}

	position.push_back(Entry(key, value));
}

void Hashtable::Delete(const std::string& key)
{
	int bucketIndex = GenerateKey(key) % bucketCount;

	auto& position = table[bucketIndex];

	for (int ix = 0; ix < (int)position.size(); ++ix)
	{
		if (position[ix].key == key)
		{
			position.erase(position.begin()+ix);
			std::cout << "항목이 삭제되었습니다.\n";

			return;
		}
	}

	std::cout << "삭제할 데이터를 찾지 못했습니다.\n";
}

bool Hashtable::Find(const std::string& key, Entry& outValue)
{
	int bucketIndex = GenerateKey(key) % bucketCount;

	if (table[bucketIndex].size() == 0)
	{
		std::cout << "해당 키로 데이터를 찾지 못했습니다.\n";
		outValue = Entry();
		return false;
	}

	for (size_t ix = 0; ix < table[bucketIndex].size(); ++ix)
	{
		if (table[bucketIndex][ix].key == key)
		{
			outValue = table[bucketIndex][ix];
			return true;
		}
	}

	std::cout << "해당 키로 데이터를 찾지 못했습니다.\n";
	outValue = Entry();
	return false;
}

//Hashtable::Entry Hashtable::Find(const std::string& key)
//{
//	int bucketIndex = GenerateKey(key) % bucketCount;
//
//	if (table[bucketIndex].size() == 0)
//	{
//		std::cout << "해당 키로 데이터를 찾지 못했습니다.\n";
//		return Entry();
//	}
//
//	for (size_t ix = 0; ix < table[bucketIndex].size(); ++ix)
//	{
//		if (table[bucketIndex][ix].key == key)
//		{
//			return table[bucketIndex][ix];
//		}
//	}
//
//	std::cout << "해당 키로 데이터를 찾지 못했습니다.\n";
//	return Entry();
//}

void Hashtable::Print()
{
	for (size_t ix = 0; ix < bucketCount; ++ix)
	{
		if (table[ix].size() == 0)
		{
			continue;
		}

		for (size_t jx = 0; jx < table[ix].size(); ++jx)
		{
			std::cout << "키: " << table[ix][jx].key
				<< " 값: " << table[ix][jx].value << std::endl;
		}
	}
}