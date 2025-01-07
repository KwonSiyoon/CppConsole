#pragma once

#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
template<typename T>
class LinkedList
{
public:
    // ������ �߻����� �� ������ �Լ��� ������ �Լ� ������ Ÿ�� ����.
    using ListEmptyErrorEvent = void (*)();

    // �� �Լ� Ÿ�� ����.
    using Comparer = bool (*)(T& left, T& right);

public:
	LinkedList()
        : first(new Node<T>()), last(new Node<T>())
	{
        // ������ ���� first�� last�� ���θ� ����Ű���� ����.
        first->next = last;
        last->previous = first;
	}
    LinkedList(ListEmptyErrorEvent errorHandler)
        : LinkedList<T>()
    {
        errorEvent = errorHandler;
    }
	~LinkedList()
	{
        if (count > 0)
        {
            Clear();
        }
        delete first;
        delete last;
	}
    // ����Ʈ �ȿ� ��� ��带 �����ϴ� �Լ�.
    void Clear()
    {
        // ����Ʈ�� ������� ���� �߻�.
        if (count == 0)
        {
            RaiseEmptyErrorEvent();
            return;
        }

        // ù ��忡�� ���� ����.
        Node<T>* current = first->next;

        // ��� ��� ����.
        while (current != nullptr && current != last)
        {
            // ���� ����.
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        // ���� ������ ����.
        count = 0;
        first->next = last;
        last->previous = first;
    }

    // ����Ʈ�� ����� �� ���� �̺�Ʈ�� �߻���Ű�� �Լ�.
    // Invoke(���� ȣ��).
    void RaiseEmptyErrorEvent()
    {
        // �Լ� �����Ͱ� �����Ǿ����� �ش� �Լ� ȣ��.
        if (errorEvent != nullptr)
        {
            errorEvent();
        }

    }

	void AddToFirst(const T& data)		// ��忡 �߰��ϴ� �Լ�.
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

        // �� ����� ���� ��带 first->next ��� ����,
        // �� ����� ���� ��带 first�� ����.
        Node<T>* next = first->next;
        newNode->next = next;
        newNode->previous = first;
        
        // ù ���(first->next)�� �� ���� ����.
        // ���� �� ����� ���� ��带 ù ���� ����.
        first->next = newNode;
        next->previous = newNode;
        
		// ����� ��� �� ���� ó��.
		++count;
	}
	void AddToLast(const T& data)			// �� �ڿ� �����ϴ� �Լ�.
	{
        // �� ��� ����.
        Node<T>* newNode = new Node<T>(data);

        // �� ����� ���� ��带 last ����,
        // �� ����� ���� ��带 last->previous�� ����.
        Node<T>* previous = last->previous;
        newNode->previous = previous;
        newNode->next = last;

        // ���������(last->previous)�� �� ���� ����.
        // ���� ������ ����� ���� ��带 �� ���� ����.
        previous->next = newNode;
        last->previous = newNode;

        // ����� ��� �� ���� ó��.
        ++count;
	}
    void Delete(const T& data/*, Comparer comparer = nullptr*/)			// �����͸� ������ �˻� �� �����ϴ� �Լ�.
    {
        // ���� ó��.
        if (count == 0)
        {
            RaiseEmptyErrorEvent();
            return;
        }

        // ������ ��� �˻�.
        Node<T>* deleteNode = first->next;
        while (deleteNode != nullptr && deleteNode != last)
        {
            // ã������ ���� ����.
            if (deleteNode->data == data)
            {
                break;
            }

            // ���� ���� �̵�(�˻� ��� ����).
            deleteNode = deleteNode->next;
        }

        // ���� ó��.
        if (deleteNode == nullptr || deleteNode == last)
        {
            RaiseEmptyErrorEvent();
            return;
        }

        // ����.
        deleteNode->previous->next = deleteNode->next;
        deleteNode->next->previous = deleteNode->previous;

        delete deleteNode;
        --count;

        //// ���� �ڵ�.
        //Node<T>* current;
        //if (comparer(current->data, data))
        //{

        //}
    }
    bool Find(const T& data, Node<T>*& outNode)
    {
        outNode = Find(data);
        if (outNode == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }


    Node<T>* Find(const T& data)
    {
        Node<T>* current = first->next;

        while (current != nullptr && current != last)
        {
            if (current->data == data)
            {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }


    void Print()					// ����� ��� ��� �Լ�.
    {
        Node<T>* current = first->next;
        while (current != nullptr && current != last)
        {
            std::cout << "Data: " << current->data << "\n";
            current = current->next;
        }
    }
    inline int Count() const		// ����� ����� ���� ��ȯ�ϴ� �Լ�(Getter).
    {
        return count;
    }

private:
	// ���(����) ���.
	Node<T>* first = nullptr;
    // ������ ���.
    Node<T>* last = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;

    // �Լ� ������ ����.
    ListEmptyErrorEvent errorEvent = nullptr;
};