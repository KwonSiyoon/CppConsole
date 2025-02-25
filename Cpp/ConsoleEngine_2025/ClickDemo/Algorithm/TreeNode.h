#pragma once

#include <iostream>
#include <string>

// 노드 색상 열거형
enum class NodeColor
{
    Red,
    Black
};

class TreeNode
{
public:
    // 생성자.
    TreeNode(int data = 0, NodeColor color = NodeColor::Red);
    ~TreeNode() = default;

    // Getter/Setter.
    // 데이터
    inline const int Data() const { return data; }
    inline void SetData(int newData) { data = newData; }

    // 색상.
    inline const NodeColor GetColor() const { return color; }
    inline void SetColor(NodeColor newColor) { color = newColor; }
    const char* ColorString() const;

    // 부모 노드.
    inline TreeNode* Parent() const { return parent; }
    inline void SetParent(TreeNode* newParent) { parent = newParent; }
    // 왼쪽 자식 노드.
    inline TreeNode* Left() const { return left; }
    inline void SetLeft(TreeNode* newLeft) { left = newLeft; }
    // 오른쪽 자식 노드.
    inline TreeNode* Right() const { return right; }
    inline void SetRight(TreeNode* newRight) { right = newRight; }

private:
    // 데이터
    int data = 0;

    // 색상.
    NodeColor color = NodeColor::Red;

    // 부모 노드.
    TreeNode* parent = nullptr;
    // 왼쪽 자식 노드.
    TreeNode* left = nullptr;
    // 오른쪽 자식 노드.
    TreeNode* right = nullptr;
};