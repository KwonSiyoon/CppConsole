#include "DFS.h"

DFS::DFS()
{
}

DFS::~DFS()
{
}

int DFS::DP_Solution(std::vector<int> numbers, int target)
{
    std::unordered_map<int, int> dp;
    dp[0] = 1;

    for (int num : numbers)
    {
        std::unordered_map<int, int> next;
        for (auto& dppair : dp)
        {
            int sum = dppair.first;
            int count = dppair.second;
            next[sum + num] += count;
            next[sum - num] += count;
        }
        dp = std::move(next);
    }
    return dp[target];
}

int DFS::DFS_Stack_solution(std::vector<int> numbers, int target)
{
    std::stack<std::pair<int, int>> st;
    st.push({ 0,0 });

    int count = 0;
    while (!st.empty())
    {
        auto& stackPair = st.top();
        int sum = stackPair.first;
        int index = stackPair.second;
        st.pop();

        if (index == numbers.size())
        {
            if (sum == target) count++;
        }
        else
        {
            st.push({ sum + numbers[index], index + 1 });
            st.push({ sum - numbers[index], index + 1 });
        }
    }
    return count;
}
