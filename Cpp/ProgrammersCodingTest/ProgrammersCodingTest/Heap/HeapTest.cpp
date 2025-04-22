#include "HeapTest.h"

int HeapTest::DiscControllerSolution(std::vector<std::vector<int>> jobs)
{
    std::sort(jobs.begin(), jobs.end());

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priorityQueue;

    int time = 0;       // 현재 시간.
    int total = 0;      // 총 대기 시간.
    int index = 0;      // jobs 순회용 인덱스.
    int count = 0;      // 처리된 작업 수.
    
    int size = jobs.size();     

    while (count < size)
    {
        // 현재 시간까지 들어온 작업들을 모두 큐에 넣기.
        while (index < size&&jobs[index][0]<=time)
        {
            int requestTime = jobs[index][0];
            int duration = jobs[index][1];
            //priorityQueue.push(std::make_pair(duration, requestTime));
            priorityQueue.push(std::pair<int,int>(duration, requestTime));
            index++;
        }

        if (!priorityQueue.empty())
        {
            std::pair<int, int> current = priorityQueue.top();
            priorityQueue.pop();

            int duration = current.first;
            int requestTime = current.second;

            time += duration;
            total += (time - requestTime);
            count++;
        }
        else
        {
            if (index < size)
            {
                time = jobs[index][0];
            }
        }

    }
    return total / size;

}
