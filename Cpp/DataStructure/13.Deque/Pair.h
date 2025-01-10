#pragma once

template<typename KeyType, typename ValueType>
class Pair
{
public:
	Pair()
		: key(), value()
	{
	}

	Pair(KeyType key, ValueType value)
		: key(key), value(value)
	{
	}

	bool operator==(const Pair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	}

	bool operator!=(const Pair<KeyType, ValueType>& other)
	{
		return key != other.key || value != other.value;
	}

	bool operator>(const Pair<KeyType, ValueType>& other)
	{
		return key > other.key;
	}

	bool operator<(const Pair<KeyType, ValueType>& other)
	{
		return key < other.key;
	}

	bool operator>=(const Pair<KeyType, ValueType>& other)
	{
		return key >= other.key;
	}

	bool operator<=(const Pair<KeyType, ValueType>& other)
	{
		return key <= other.key;
	}

	KeyType key;
	ValueType value;
};