﻿#pragma once

#include <vector>

template<typename T>
void SafeDelete(T*& t)
{
    if (t)
    {
        delete t;
        t = nullptr;
    }
}

// A* 길찾기 기능 처리 클래스.
class Node;
class AStar
{
    // 이동 방향 구조체.
    struct Direction
    {
        // 방향.
        int x = 0;
        int y = 0;

        // 비용.
        float cost = 0.0f;
    };

public:
    AStar();
    ~AStar();

    // 경로 검색 함수.
    std::vector<Node*> FindPath(Node* startNode, Node* goalNode, const std::vector<std::vector<int>>& grid);

    // 그리드 출력 함수.
    void DisplayGridWithPath(std::vector<std::vector<int>>& grid, const std::vector<Node*>& path);

private:
    // 탐색을 완료한 후에 최적 경로를 반환하는 함수.
    // 목표 노드로부터 부모 노드를 역추적해 구함.
    std::vector<Node*> ConstructPath(Node* goalNode);

    // hCost 계산 함수.
    float CalculateHeuristic(Node* currentNode, Node* goalNode);

    // 탐색하려는 위치가 범위 안에 있는지 확인하는 함수.
    bool IsInRange(int x, int y, const std::vector<std::vector<int>>& grid);

    // 이미 방문한 위치인지 확인하는 함수.
    bool HasVisited(int x, int y, float gCost);

    // 탐색하려는 위치가 목표위치인지 확인하는 함수.
    bool IsDestination(const Node* node);

private:
    // 열린 리스트.
    std::vector<Node*> openList;
    // 닫힌 리스트.
    std::vector<Node*> closedList;

    // 시작 노드.
    Node* startNode = nullptr;

    // 목표 노드.
    Node* goalNode = nullptr;


};