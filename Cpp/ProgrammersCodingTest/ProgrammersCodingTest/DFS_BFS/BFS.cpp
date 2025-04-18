#include "BFS.h"

BFS::BFS()
{
}

BFS::~BFS()
{
}

int BFS::SearchSolution(std::vector<int> numbers, int target)
{
    std::queue<std::pair<int, int>> q;
    q.push({ 0, 0 }); // 초기값 (합, 인덱스)

    int count = 0;
    while (!q.empty())
    {
        auto& queuePair = q.front();
        int sum = queuePair.first;
        int index = queuePair.second;
        q.pop();

        if (index == numbers.size())
        { // 모든 숫자를 다 사용했을 때
            if (sum == target) count++;
        }
        else
        {
            q.push({ sum + numbers[index], index + 1 });
            q.push({ sum - numbers[index], index + 1 });
        }
    }
    return count;
}

// 입국심사 이분탐색.
long long BFS::BinarySearchSolution(int n, std::vector<int> times)
{
    int maxTime = times[0];
    for (int i = 1; i < times.size(); ++i)
    {
        if (times[i] > maxTime)
        {
            maxTime = times[i];
        }
    }

    long long left = 1;
    long long right = static_cast<long long>(maxTime * n);
    long long answer = right;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long total = 0;
        for (int i = 0; i < times.size(); ++i)
        {
            total += mid / times[i];
        }

        if (total >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}
