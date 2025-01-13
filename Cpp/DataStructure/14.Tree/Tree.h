#pragma once

#include "List.h"
#include "Node.h"
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif
template<typename T>
class Tree
{
public:
    Tree(const T& data)
    {
        // 루트 노드 생성.
        root = new Node<T>(data);
    }
    // 소멸자.
    ~Tree()
    {
        // 재귀적으로 자손 노드 삭제.
        DestroyRecursive(root);
    }
    // 부모 노드 값을 사용해 자손을 추가하는 함수.
    void AddChild(const T& parentData, const T& childData)
    {
        // 부모 노드 검색.
        Node<T>* parent = nullptr;
        if (FindRecursive(parentData, root, &parent))
        {
            parent->AddChild(childData);
            return;
        }
        std::cout << "해당 값을 찾는 부모 노드가 없어서 추가 실패.\n";
    }
    // 자손 추가.
    void AddChild(Node<T>* child, Node<T>* parent = nullptr)
    {
        child->parent = parent == nullptr ? root : parent;
        child->parent->AddChild(child);
    }
    void AddChild(const T& data, Node<T>* parent = nullptr)
    {
        AddChild(new Node<T>(data), parent);
    }
    // 노드를 삭제하는 함수.
    bool Remove(const T& data)
    {
        // 재귀적으로 삭제하는 함수 추가 및 호출.
        RemoveRecursive(data, root);
    }
    // 노드 검색 함수.
    bool Find(const T& data, Node<T>** outNode)
    {
        // 재귀 검색 함수 호출 및 결과 반환.
        return FindRecursive(data, root, outNode);
    }

    // 순회(방문).
    // 전위 순회(부모 -> 자손)
    void PreorderTraverse(int depth = 0)
    {
        PreorderTraverseRecursive(root, depth);
    }

private:
    // 전위 순회 재귀 함수.
    void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
    {
        // 종료 조건.
        if (node == nullptr)
        {
            return;
        }

        // 뎁스 출력.
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "  ";
        }

        // 부모 노드.
        std::cout << node->data << "\n";

        // 자손 노드 출력.
        List<Node<T>*>* children = node->children;
        if (children->Size() == 0)
        {
            return;
        }
        for (int i = 0; i < children->Size(); ++i)
        {
            Node<T>* child = children->At(i);
            PreorderTraverseRecursive(child, depth + 1);
        }
    }

    // 노드 삭제 재귀 함수.
    bool RemoveRecursive(const T& data, Node<T>* node)
    {
        // 삭제할 노드 검색.
        Node<T>* outNode = nullptr;
        if (FindRecursive(data, node, outNode))
        {
            // 검색 성공
            // 부모 노드의 자손 목록에서 제거.
            Node<T>* parent = outNode->parent;
            if (parent != nullptr)
            {
                parent->children->Remove(outNode);
            }
            // 제거할 자손이 있는 경우에는 자손 제거.
            List<Node<T>*>* children = outNode->children;
            while (children != nullptr && children->Size() > 0)
            {
                outNode->RemoveChild(children->At(0));
            }
            // 메모리 삭제.
            delete outNode;
            outNode = nullptr;
            // 삭제 성공.
            return true;
        }
        // 삭제 실패.
        return false;
    }

    // 자손 노드를 포함해 모든 노드를 재귀적으로 삭제하는 함수.
    void DestroyRecursive(Node<T>* node)
    {
        // 자손 리스트 확인 후 재귀적으로 삭제 진행.
        List<Node<T>*>* children = node->children;
        while (children != nullptr && children->Size() > 0)
        {
            Node<T>* child = children->At(0);
            DestroyRecursive(child);
        }
        // 부모 노드가 있으면 부모의 자손 목록에서 자신 제거.
        Node<T>* parent = node->parent;
        if (parent != nullptr)
        {
            parent->children->Remove(node);
        }
        // 삭제
        delete node;
        node = nullptr;
    }

    // 재귀적으로 검색하는 함수.
    // data : 검색에 사용할 값. 이 값을 가진 노드를 검색.
    // node : 검색 위치.
    // outNode : 검색에 성공했을 때 출력(반환)할 파라미터.
    bool FindRecursive(const T& data, Node<T>* node, Node<T>** outNode)
    {
        // 예외 처리.
        if (node == nullptr)
        {
            *outNode = nullptr;
            return false;
        }
        // 노드 검색에 성공한 경우.
        if (node->data == data)
        {
            *outNode = node;
            return true;
        }
        // 재귀적으로 자손 노드 검색 진행.
        List<Node<T>*>* children = node->children;
        int size = children->Size();
        for (int i = 0; i < size; ++i)
        {
            // 자손 노드 검색.
            Node<T>* child = children->At(i);
            bool result = FindRecursive(data, child, outNode);
            // 검색에 성공했으면 종료.
            if (result)
            {
                return true;
            }
        }
        // 검색 실패.
        *outNode = nullptr;
        return false;
    }


private:
    // 루트 노드.
    Node<T>* root = nullptr;
};