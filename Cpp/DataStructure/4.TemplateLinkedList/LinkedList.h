#pragma once

#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
template<typename T>
class LinkedList
{
public:
	LinkedList()
	{

	}
	~LinkedList()
	{
        if (first != nullptr)
        {
            Node<T>* current = first;
            Node<T>* deleteNode = nullptr;
            while (current != nullptr)
            {
                deleteNode = current;
                current = current->next;

                delete deleteNode;
            }
            std::cout << "��ũ�� ����Ʈ �Ҹ��� ����";
        }
	}
	void AddToFisrt(const T& data)		// ��忡 �߰��ϴ� �Լ�.
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		// 1. ���� ��尡 ���� ���.
		if (first == nullptr)
		{
			// ��� ��带 newNode�� ����.
			first = newNode;
		}
		// 2. ��尡 �ִ� ���
		else
		{
			// �� ����� ���� ��带 ������ ��� ���� ����.
			newNode->next = first;
			// ��� ��带 �� ���� ��ü.
			first = newNode;
		}
		// ����� ��� �� ���� ó��.
		++count;
	}
	void Insert(const T& data)			// �� �ڿ� �����ϴ� �Լ�.
	{
        // �� ��� ����.
        Node<T>* newNode = new Node<T>(data);
        // ������ ��ġ ã��.
        // 1. ��尡 ����ִ� ���.
        if (first == nullptr)
        {
            first = newNode;
        }
        // ������ ��ġ�� �˻� �� ��� ����.
        else
        {
            // ��� ������ 2���� ����� �˻�.
            Node<T>* current = first;
            Node<T>* trail = nullptr;

            // ��ġ �˻�
            while (current != nullptr)
            {
                // �� ��.
                if (current->data >= data)
                {
                    break;
                }

                // ���� ���� �̵�.
                trail = current;
                current = current->next;
            }

            // �˻��� ����� Ȯ���ؼ� ó��.
            // �˻��� ��尡 ����� ���
            if (current == first)
            {
                newNode->next = first;
                first = newNode;
            }
            // �˻��� ��尡 �߰� ��ġ�� ���.
            else
            {
                newNode->next = current;
                trail->next = newNode;
            }
        }

        // ����� �� ����ó��.
        ++count;
	}
    void Delete(const T& data)			// �����͸� ������ �˻� �� �����ϴ� �Լ�.
    {
        // ������ ��� ã��.
        // ���� ó��.
        if (first == nullptr)
        {
            std::cout << "����Ʈ�� ����־� ������ �Ұ����մϴ�.\n";
            return;
        }
        // �˻� ����.
        Node<T>* current = first;
        Node<T>* trail = nullptr;
        while (current != nullptr)
        {
            // �� ��
            if (current->data == data)
            {
                break;
            }
            // ��� �̵�.
            trail = current;
            current = current->next;
        }
        // �˻��� ��� 2����.
        // 1. ��ã�� ���.
        if (current == nullptr)
        {
            std::cout << "�� " << data << "�� ã�� ���߽��ϴ�.\n";
            return;
        }
        // 2. ã�����.
        if (current == first)
        {
            // ��� ��� ��ü.
            first = first->next;
        }
        else
        {
            trail->next = current->next;
        }
        // ��� ����.
        delete current;
        // ����� ����� �� ���� ó��.
        --count;
    }
    void Print()					// ����� ��� ��� �Լ�.
    {
        Node<T>* current = first;
        while (current != nullptr)
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

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;

};