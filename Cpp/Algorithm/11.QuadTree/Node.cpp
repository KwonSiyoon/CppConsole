﻿#include "Node.h"
#include "QuadTree.h"

Node::Node(const Bounds& bounds, int depth)
    : bounds(bounds), depth(depth)
{
}

Node::~Node()
{
    //// 현재 노드에 저장된 모든 노드 제거.
    //for (Node* node : points)
    //{
    //    SafeDelete(node);
    //}
    //points.clear();

    //// 자식 노드 정리.
    //ClearChildren();

    Clear();
}

void Node::Insert(Node* node)
{
    // 겹치는 영역 확인.
    NodeIndex result = TestRegion(node->GetBounds());

    // 겹치면 현재 노드에 추가.
    if (result == NodeIndex::Straddling)
    {
        points.emplace_back(node);
    }
    // 겹치지 않고 범위안에 있는 경우.
    else if (result != NodeIndex::OutOfArea)
    {
        if (Subdivide())
        {
            // 나눌 수 있으면 나눈 후 들어와서 처리.
            if (result == NodeIndex::TopLeft)
            {
                topLeft->Insert(node);
            }
            else if (result == NodeIndex::TopRight)
            {
                topRight->Insert(node);
            }
            else if (result == NodeIndex::BottomLeft)
            {
                bottomLeft->Insert(node);
            }
            else if (result == NodeIndex::BottomRight)
            {
                bottomRight->Insert(node);
            }
        }
        // 더 이상 나눌 수 없는 경우.
        else
        {
            points.emplace_back(node);
        }
    }
}

void Node::Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes)
{
    // 현재 노드 추가.
    possibleNodes.emplace_back(this);

    // 영역이 분할됐으면, 자식 노드도 추가 검사.
    if (IsDivided())
    {
        // 전달 받은 영역과 겹치는 4분면 목록 확인.
        std::vector<NodeIndex> quads = GetQuads(queryBounds);

        // 겹치는 4분면을 기준으로 검사 진행(재귀).
        for (NodeIndex& index : quads)
        {
            if (index == NodeIndex::TopLeft)
            {
                topLeft->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::TopRight)
            {
                topRight->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::BottomLeft)
            {
                bottomLeft->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::BottomRight)
            {
                bottomRight->Query(queryBounds, possibleNodes);
            }
        }
    }
}

void Node::Clear()
{
    // 현재 노드 제거.
    for (Node* node : points)
    {
        SafeDelete(node);
    }

    // 리스트 정리.
    points.clear();

    // 분할된 경우 자식 정리.
    if (IsDivided())
    {
        topLeft->Clear();
        topRight->Clear();
        bottomLeft->Clear();
        bottomRight->Clear();

        ClearChildren();
    }

}

bool Node::Subdivide()
{
    // 최대 깊이에 도달했으면 더이상 안나눔.
    if (depth == QuadTree::maxDepth)
    {
        return false;
    }

    // 아직 분할 안됐으면, 분할 진행.
    if (!IsDivided())
    {
        // 영역을 나누기 위한 값 계산.
        float x = bounds.X();
        float y = bounds.Y();
        float halfWidth = bounds.Width() * 0.5f;
        float halfHeight = bounds.Height() * 0.5f;

        // 각 4분면의 자식 객체 생성.
        topLeft = new Node(Bounds(x, y, halfWidth, halfHeight), depth + 1);
        topRight = new Node(Bounds(x+ halfWidth, y, halfWidth, halfHeight), depth + 1);
        bottomLeft = new Node(Bounds(x, y + halfHeight, halfWidth, halfHeight), depth + 1);
        bottomRight = new Node(Bounds(x + halfWidth, y + halfHeight, halfWidth, halfHeight), depth + 1);

    }

    return true;
}

bool Node::IsDivided()
{
    return topLeft != nullptr;
}

void Node::ClearChildren()
{
    // 분할 진행됐는지 확인.
    if (IsDivided())
    {
        SafeDelete(topLeft);
        SafeDelete(topRight);
        SafeDelete(bottomLeft);
        SafeDelete(bottomRight);
    }
}

NodeIndex Node::TestRegion(const Bounds& bounds)
{
    // 전달된 bounds와 겹치는 4분면 목록 확인.
    std::vector<NodeIndex> quads = GetQuads(bounds);

    // 겹치는 곳이 없으면 영역 밖으로 표시.
    if (quads.size() == 0)
    {
        return NodeIndex::OutOfArea;
    }
    // 하나만 겹친 경우 해당 4분면 반환.
    if (quads.size() == 1)
    {
        return quads[0];
    }

    // 여러 영역과 겹친 경우.
    return NodeIndex::Straddling;
}

std::vector<NodeIndex> Node::GetQuads(const Bounds& bounds)
{
    std::vector<NodeIndex> quads;

    // 영역 계산에 필요한 변수.
    float x = this->bounds.X();
    float y = this->bounds.Y();
    float halfWidth = this->bounds.Width() * 0.5f;
    float halfHeight = this->bounds.Height() * 0.5f;
    float centerX = x + halfWidth;
    float centerY = y + halfHeight;

    // 왼쪽 영역이랑 겹치는지 확인.
    bool left = bounds.X() < centerX && bounds.MaxX() >= x;

    // 오른쪽 영역이랑 겹치는지 확인.
    bool right = bounds.MaxX() >= centerX && bounds.X() < this->bounds.MaxX();

    // 위쪽 영역이랑 겹치는지 확인.
    bool top = bounds.Y() < centerY && bounds.MaxY() >= y;

    // 아래쪽 영역이랑 겹치는지 확인.
    bool bottom = bounds.MaxY() >= centerY && bounds.Y() < this->bounds.MaxY();

    if (top && left)
    {
        quads.emplace_back(NodeIndex::TopLeft);
    }
    if (top && right)
    {
        quads.emplace_back(NodeIndex::TopRight);
    }
    if (bottom && left)
    {
        quads.emplace_back(NodeIndex::BottomLeft);
    }
    if (bottom && right)
    {
        quads.emplace_back(NodeIndex::BottomRight);
    }

    return quads;
}
