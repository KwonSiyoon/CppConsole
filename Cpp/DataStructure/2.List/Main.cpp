#include <iostream>
#include <vector>		// ���� �迭
//#include <list>			// ���Ḯ��Ʈ.

// ���� ���̺귯��.
// Vector2 / Vector3 / Vector4

// �ݺ���(Iterator) Ŭ����.
template<typename List>
class VectorIterator
{
public:
	// Ÿ�� ����.
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{

	}

	// ������ ���� ���� ������ �����ε�.
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}
	// ������ ���� ���� ������ �����ε�.
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}
	// ������ ���� ���� ������ �����ε�.
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}
	// ������ ���� ���� ������ �����ε�.
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// �ε��� ������ �����ε�.
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// ������ ������ �����ε�
	PointerType operator->()
	{
		return pointer;
	}
	// �� ��ȯ ������.
	ReferenceType operator*()
	{
		return *pointer;
	}

	// �� ������.
	bool operator==(const VectorIterator& other) const
	{
		return pointer == other.pointer;
	}
	bool operator!=(const VectorIterator& other) const
	{
		//return pointer != other.pointer;
		return !(*this == other);
	}

private:
	PointerType pointer;
};


// ���� �迭(����Ʈ) Ŭ����. ���ø�.
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// �ʱ� ������ ���� ����.
		data = new T[capacity];
	}

	~List()
	{
		// �����Ͱ� ����Ű�� �� �迭 ���� ����.
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	// ���� �߰�.
	void PushBack(const T& value)
	{
		//�ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (count == capacity)
		{
			ReAllocate(capacity*2);
		}
		data[count] = value;			// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		++count;						// ����� ����� �� ���� ó��.
	}

	// Move �߰�.
	void PushBack(T&& value)
	{
		//�ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}
		data[count] = std::move(value);		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		++count;							// ����� ����� �� ���� ó��.
	}

	// ���� �Լ�.
	T& At(int index)
	{
		// ���� ó��.
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	// ���� �Լ�.
	const T& At(int index) const
	{
		// ���� ó��.
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	// ������ �����ε�.
	T& operator[](int index)
	{
		// ���� ó��.
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	// ������ �����ε�.
	const T& operator[](int index) const
	{
		// ���� ó��.
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	// Iterator ���� �Լ�.
	Iterator begin()
	{
		return Iterator(data);
	}
	Iterator end()
	{
		return Iterator(data + count);
	}


	// Getter.
	int Count() const { return count; }					// ��� �� ��ȯ.
	int Capacity() const { return capacity; }			// ���� �뷮 ��ȯ.
	T* Data() const { return data; }					// �迭 �ּ� ��ȯ.

private:
	// ������ ������ ������ �� ������ �ø��� �Լ�.
	void ReAllocate(size_t newCapacity)
	{
		// 1. ���ο� �޸� ���� �Ҵ�(Allocate).
		// 2. ������ ������ ����.
		// 3. ���� ������ �� �ӽ� ������ ����.
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, newCapacity);
		// ����.
		//for (int i = 0; i < count; ++i)
		//{
		//	newBlock[i] = data[i];								// ���� ��� 1
		//	newBlock[i] = std::move(data[i]);					// ���� ��� 2
		//}														
		memcpy(newBlock, data, sizeof(T) * count);				// ���� ��� 3. �޸� ����.

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}


private:
	// ������ ����. (���� �Ҵ��� �迭 ����.)
	T* data = nullptr;

	// �뷮
	int capacity = 2;

	// �迭 ������ ��.
	int count = 0;
};


int main()
{
	// ���� �迭 ��ü ����.
	List<int> list;
	char buffer[256];
	
	// ���� �߰�.
	for (int i = 0; i < 100; ++i)
	{
		list.PushBack(100+i);
		/*snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity());
		std::cout << buffer;*/
	}

	// Standard Template Library(STL) ���� �迭.
	std::vector<int> vector;
	//{
	//	1,2,3,4,5
	//};
	
	for (int i = 0; i < 100; ++i)
	{
		vector.push_back(i);
	}

	// �б�.
	// Randge-Based Loop / Ranged Loop.
	for (const auto& item : vector)
	{
		std::cout << item << "\n";
	}

	for (const auto& item : list)
	{
		std::cout << item << "\n";
	}

	snprintf(buffer, 256, "%d, %d\n", static_cast<int>(vector.size()), static_cast<int>(vector.capacity()));
	std::cout << buffer;
		
	std::cin.get();
}