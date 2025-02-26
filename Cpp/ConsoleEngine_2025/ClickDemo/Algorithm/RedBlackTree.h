#pragma once

#include <iostream>
#include <string>
#include "TreeNode.h"
#include <Windows.h>

// 레드 블랙 트리 클래스.
class RedBlackTree
{
public:
    RedBlackTree();
    ~RedBlackTree();

    // 노드 검색 함수.
    bool Find(int data, TreeNode** outNode);

    // 노드 추가 함수.
    bool Insert(int data);

    // 노드 삭제 함수.
    void Remove(int data);

    // 노드 출력 함수.
    void Print(int depth = 0, int blackCount = 0);

    TreeNode* Root() { return root; }
    TreeNode* Nil() { return nil; }

private:
    // 노드 생성 함수.
    TreeNode* CreateNode(int data, NodeColor color);

    // 노드 검색 재귀 함수.
    bool FindRecursive(TreeNode* node, TreeNode** outNode, int data);

    // 노드 추가 함수(새 노드 전달).
    void Insert(TreeNode* newNode);

    // 트리에 노드를 추가하는 재귀 함수.
    void InsertRecursive(TreeNode* node, TreeNode* newNode);

    // 노드 삽입 후 재정렬을 처리하는 함수.
    void RestructureAfterInsert(TreeNode* newNode);

    // 노드 삭제 후 재정렬 처리 함수.
    void RestructureAfterRemove(TreeNode* node);

    // 좌회전 함수.
    // node: 회전의 기준점(pivot).
    void RotateToLeft(TreeNode* node);

    // 우회전 함수.
    // node: 회전의 기준점(pivot).
    void RotateToRight(TreeNode* node);

    // 트리에서 최소 값을 가진 노드를 검색하는 함수.
    TreeNode* FindMinRecursive(TreeNode* node);

    // 트리에서 최대 값을 가진 노드를 검색하는 함수.
    TreeNode* FindMaxRecursive(TreeNode* node);

    // 노드 삭제 함수.
    void RemoveImpl(TreeNode* node);

    // 삭제 함수.
    void DestroyRecursive(TreeNode* node);

    void PrintRecursive(TreeNode* node, int depth, int blackCount);
private:
    // 루트 노드.
    TreeNode* root = nullptr;

    // Nil 노드.
    TreeNode* nil = nullptr;

};


// 콘솔 텍스트 색상 열거형.
enum class TextColor
{
    Red = FOREGROUND_RED,
    Green = FOREGROUND_GREEN,
    Blue = FOREGROUND_BLUE,
    White = Red | Green | Blue
};

// 콘솔 텍스트 색상 설정 함수.
void SetTextColor(TextColor color);

