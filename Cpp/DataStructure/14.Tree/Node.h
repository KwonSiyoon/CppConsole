#pragma once

#include "List.h"

// 트리의 노드 클래스.
template<typename T>
class Node
{
    // 친구 등록.
    //friend class Node<T>; // 서로다른 노드에 접근 가능.

    template<typename T>
    friend class Tree;

public:
    Node(const T& data = T())
        : data(data)
    {
        // 자손 노드 저장할 리스트 생성.
        children = new List<Node<T>*>();
    }
    // 복사 생성자 제거.
    Node(const Node& other) = delete;
    // 소멸자.
    ~Node()
    {
        parent = nullptr;
        delete children;
        children = nullptr;
    }
    // 값을 전달해서 자손을 추가하는 함수.
    void AddChild(const T& newData)
    {
        AddChild(new Node<T>(newData));
    }

    // 생성한 노드를 직접 추가해 자손을 추가하는 함수.
    void AddChild(Node<T>* newChild)
    {
        // 부모 노드 설정.
        newChild->parent = this;

        // 자손 노드 리스트에 새로운 자손 추가.
        children->PushBack(newChild);
    }

    // 자손 삭제 함수 - 제거할 자손 노드를 전달해 삭제.
    void RemoveChild(Node<T>& child)
    {
        // 재귀적으로 검색해서 삭제.
        RemoveChildRecursive(child);

    }
    // 하위 노드를 포함해 노드의 수를 반환하는 함수.
    int GetCount()
    {
        // 노드 수를 셀 때 자신 포함.
        int count = 1;
        // 자손 노드 수 세기.
        for (int i = 0; i < children->Size(); ++i)
        {
            count += children->At(i)->GetCount();
        }

        // 카운트 반환.
        return count;
    }
private:
    // 재귀적으로 삭제하는 함수.
    void RemoveChildRecursive(Node<T>* child)
    {
        // 예외처리.
        if (child == nullptr)
        {
            return;
        }
        // 찾아서 삭제.
        // 하위 노드 리스트 확인.
        List<Node<T>*>* children = child->children;

        // 경우의 수1 : 자손이 없는 경우.
        // children이 null이거나 크기가 0인 경우.
        if (children == nullptr || children->Size() == 0)
        {
            // 부모의 자손 목록에서 자신을 제거.
            child->parent->children->Remove(child);
            // 노드 삭제.
            delete child;
            child = nullptr;
            return;
        }
        // 경우의 수2 : 자손이 있는 경우.
        while (children != nullptr && children->Size() > 0)
        {
            // 자손을 순회하면서 재귀적으로 자손의 하위 노드 제거.
            RemoveChildRecursive(children->At(0));
        }
        // 모든 자손을 제거한 후에 부모 노드에서 제거.
        child->parent->children->Remove(child);

        // 메모리 삭제.
        delete child;
        child = nullptr;
    }
private:
    // 노드에 저장하는 데이터.
    T data;

    // 부모 노드 참조 변수.
    Node<T>* parent = nullptr;

    // 자손 노드 목록.
    List<Node<T>*>* children = nullptr;

};