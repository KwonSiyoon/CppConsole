#pragma once
#include <iostream>

// 이진 트리에 사용할 노드 클래스.
template<typename T>
class Node
{
    // 이진 트리 클래스를 프렌드로 선언.
    template<typename T>
    friend class BinaryTree;

public:
    Node()
    {

    }
    Node(const T& data)
        :data(data)
    {

    }
    ~Node()
    {

    }

    // 삽입 함수.
    void AddLeftChild(Node<T>* child)
    {
        // 1. 새로운 자손의 부모를 이 노드로 지정.
        child->parent = this;
        // 2. 이 노드의 왼쪽 자손을 새 노드로 지정.
        left = child;
    }
    void AddLeftChild(const T& data)
    {
        AddLeftChild(new Node<T>(data));
    }

    // 삽입 함수.
    void AddRightChild(Node<T>* child)
    {
        // 1. 새로운 자손의 부모를 이 노드로 지정.
        child->parent = this;
        // 2. 이 노드의 오른쪽 자손을 새 노드로 지정.
        right = child;
    }
    void AddRightChild(const T& data)
    {
        AddRightChild(new Node<T>(data));
    }

    // 삭제 함수.
    void Destroy()
    {
        // 노드의 부모가 있는 경우 삭제 진행.
        if (parent)
        {
            // 이 노드가 부모의 왼쪽 자손일 때.
            if (parent->left == this)
            {
                parent->left = nullptr;
            }

            // 이 노드가 부모의 오른쪽 자손일 때.
            if (parent->right == this)
            {
                parent->right = nullptr;
            }
        }
        DestroyRecursive(this);
    }

private:
    // 삭제 재귀 함수.
    void DestroyRecursive(Node<T>* node)
    {
        // 탈출 조건.
        if (node == nullptr)
        {
            return;
        }
        // 자손 노드의 존재 확인.
        Node<T>* leftChild = node->left;
        Node<T>* rightChild = node->right;

        // 1. 자손이 없는 경우.
        if (leftChild == nullptr && rightChild == nullptr)
        {
            delete node;
            node = nullptr;
            return;
        }
        // 자손 재귀 호출.
        DestroyRecursive(leftChild);
        DestroyRecursive(rightChild);

        delete node;
        node = nullptr;
        return;
    }

private:
    T data;                         // 데이터.
    Node<T>* parent = nullptr;      // 부모 노드.
    Node<T>* left = nullptr;        // 왼쪽 자손 노드.
    Node<T>* right = nullptr;       // 오른쪽 자손 노드.

};