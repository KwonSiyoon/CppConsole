#include "StackQueue.h"

using namespace std;
std::vector<int> StackQueue::DevelopFunctionSolution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;
    std::queue<int> daysQueue;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remaining = 100 - progresses[i];
        //int days = ceil((double)remaining / speeds[i]);
        int days = remaining / speeds[i];
        if (remaining%speeds[i] > 0)
        {
            ++days;
        }
        daysQueue.push(days);
    }

    while (!daysQueue.empty())
    {
        int currentDay = daysQueue.front();
        daysQueue.pop();
        int count = 1;

        while (!daysQueue.empty() && daysQueue.front() <= currentDay)
        {
            daysQueue.pop();
            count++;
        }

        answer.push_back(count);
    }
    return answer;
}

int NetworkSolution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i)
    {
        q.emplace(pair<int, int>(0, i));
    }

    return answer;
}
