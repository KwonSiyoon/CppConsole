#pragma once

#include "Node.h"

template<typename T>
class BinaryTree
{
public:
    BinaryTree(const T& data)
    {
        root = new Node<T>(data);
    }
    ~BinaryTree()
    {
        root->Destroy();
    }

    void AddLeftChild(const T& parentData, const T& childData)
    {
        // 부모 노드 검색.
        Node<T>* outParent = nullptr;
        if (Find(parentData, &outParent))
        {
            outParent->AddLeftChild(childData);
            return;
        }
        // 검색 실패하면 메시지 출력.
        std::cout << "Error: 부모 노드를 찾지 못해 자손 노드 추가 실패.\n";
    }

    void AddRightChild(const T& parentData, const T& childData)
    {
        // 부모 노드 검색.
        Node<T>* outParent = nullptr;
        if (Find(parentData, &outParent))
        {
            outParent->AddRightChild(childData);
            return;
        }
        // 검색 실패하면 메시지 출력.
        std::cout << "Error: 부모 노드를 찾지 못해 자손 노드 추가 실패.\n";
    }
    // 값을 기반으로 노드를 검색하는 함수.
    bool Find(const T& data, Node<T>** outNode)
    {
        return FindRecursive(data, root, outNode);
    }

    // 데이터를 기반으로 노드를 삭제하는 함수.
    bool DeleteNode(const T& data)
    {
        // 삭제 노드 검색.
        Node<T>* outNode = nullptr;
        if (Find(data, &outNode))
        {
            // 검색된 노드 제거.
            outNode->Destroy();
            return true;
        }
        std::cout << "삭제할 노드 검색 실패. 삭제 실패.\n";
        return false;
    }
    // 전위 순회 함수.
    void PreorderTraverse(int depth = 0)
    {
        std::cout << "전위 순회 시작 -------------\n";
        PreorderTraverseRecursive(root, depth);
        std::cout << "전위 순회 끝 ---------------\n";
    }


private:
    // 전위 순회 재귀 함수.
    void PreorderTraverseRecursive(Node<T>* node, int depth)
    {
        // 탈출 조건.
        if (node == nullptr)
        {
            return;
        }
        // 뎁스 출력.
        for (int i = 0; i < depth; ++i)
        {
            std::cout << " ";
        }
        // 부모 노드 출력.
        std::cout << node->data << "\n";
        // 왼쪽 하위 노드 출력.
        PreorderTraverseRecursive(node->left, depth + 1);
        // 오른쪽 하위 노드 출력.
        PreorderTraverseRecursive(node->right, depth + 1);


    }


    // 검색 재귀 함수.
    bool FindRecursive(const T& data, Node<T> * node, Node<T>** outNode)
    {
        // 탈출 조건.
        if (node == nullptr)
        {
            *outNode = nullptr;
            return false;
        }
        // 현재 노드에서 검색.
        if (node->data == data)
        {
            *outNode = node;
            return true;
        }
        // 왼쪽 하위로 내려가서 검색.
        if (FindRecursive(data, node->left, outNode))
        {
            return true;
        }
        // 오른쪽 하위로 내려가서 검색.
        if (FindRecursive(data, node->right, outNode))
        {
            return true;
        }
        // 검색 실패.
        *outNode = nullptr;
        return false;
    }

private:
    // 루트 노드.
    Node<T>* root = nullptr;
};