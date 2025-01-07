#include "LinkedList.h"

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
    // Todo: 작업목록.
    if (head != nullptr)
    {
        Node* current = head;
        Node* deleteNode = nullptr;
        while (current != nullptr)
        {
            deleteNode = current;
            current = current->next;

            delete deleteNode;
        }
        std::cout << "링크드 리스트 소멸자 진행";
    }
}

void LinkedList::AddToHead(int data)
{
    // 새 노드 생성.
    Node* newNode = new Node(data);
    
    // 1. 현재 헤드가 없는 경우.
    if (head == nullptr)
    {
        // 헤드 노드를 newNode로 설정.
        head = newNode;
    }
    // 2. 헤드가 있는 경우
    else
    {
        // 새 노드의 다음 노드를 기존의 헤드 노드로 설정.
        newNode->next = head;
        // 헤드 노드를 새 노드로 교체.
        head = newNode;
    }
    // 저장된 노드 수 증가 처리.
    ++count;
}

void LinkedList::Insert(int data)
{
    // 새 노드 생성.
    Node* newNode = new Node(data);
    // 삽입할 위치 찾기.
    // 1. 헤드가 비어있는 경우.
    if (head == nullptr)
    {
        head = newNode;
    }
    // 삽입할 위치를 검색 후 노드 삽입.
    else
    {
        // 노드 포인터 2개를 사용해 검색.
        Node* current = head;
        Node* trail = nullptr;

        // 위치 검색
        while (current != nullptr)
        {
            // 값 비교.
            if (current->data >= data)
            {
                break;
            }

            // 다음 노드로 이동.
            trail = current;
            current = current->next;
        }

        // 검색된 결과를 확인해서 처리.
        // 검색된 노드가 헤드인 경우
        if (current == head)
        {
            newNode->next = head;
            head = newNode;
        }
        // 검색된 노드가 중간 위치인 경우.
        else
        {
            newNode->next = current;
            trail->next = newNode;
        }
    }

    // 요소의 수 증가처리.
    ++count;
}

void LinkedList::Delete(int data)
{
    // 삭제할 노드 찾기.
    // 예외 처리.
    if (head == nullptr)
    {
        std::cout << "리스트가 비어있어 삭제가 불가능합니다.\n";
        return;
    }
    // 검색 진행.
    Node* current = head;
    Node* trail = nullptr;
    while (current!=nullptr)
    {
        // 값 비교
        if (current->data == data)
        {
            break;
        }
        // 노드 이동.
        trail = current;
        current = current->next;
    }
    // 검색의 결과 2가지.
    // 1. 못찾은 경우.
    if (current == nullptr)
    {
        std::cout << "값 "<<data<<"를 찾지 못했습니다.\n";
        return;
    }
    // 2. 찾은경우.
    if (current == head)
    {
        // 헤드 노드 교체.
        head = head->next;
    }
    else
    {
        trail->next = current->next;
    }
    // 노드 삭제.
    delete current;
    // 저장된 요소의 수 감소 처리.
    --count;
}

void LinkedList::Print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << *current << "\n";
        current = current->next;
    }
}

inline int LinkedList::Count() const
{
    return count;
}
