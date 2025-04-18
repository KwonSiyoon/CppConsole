#include "GraphTest.h"

GraphTest::GraphTest()
{
}

GraphTest::~GraphTest()
{
}

int GraphTest::FarestSolution(int n, std::vector<std::vector<int>> edge)
{
    // 1. 그래프 구성 (1-based indexing)
    std::vector<std::vector<int>> graph(n + 1);  // 인접 리스트
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);  // 무방향 그래프
    }

    // 2. BFS 준비
    std::vector<int> distance(n + 1, -1);  // -1: 방문하지 않음
    std::queue<int> q;

    distance[1] = 0;  // 시작 노드 거리 = 0
    q.push(1);

    // 3. BFS 수행
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            if (distance[next] == -1) // 방문하지 않았다면.
            { 
                distance[next] = distance[curr] + 1;
                q.push(next);
            }
        }
    }

    // 4. 최대 거리 찾기
    int maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        if (distance[i] > maxDist)
        {
            maxDist = distance[i];
        }
    }

    // 5. 최대 거리인 노드 개수 세기
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (distance[i] == maxDist)
        {
            count++;
        }
    }

    return count;
}
