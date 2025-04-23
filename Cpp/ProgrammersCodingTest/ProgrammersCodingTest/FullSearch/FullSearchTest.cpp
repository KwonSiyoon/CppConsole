#include "FullSearchTest.h"

std::vector<int> FullSearchTest::MockExamSolution(std::vector<int> answers)
{
    std::vector<int> first = { 1, 2, 3, 4, 5 };
    std::vector<int> second = { 2, 1, 2, 3, 2, 4, 2, 5 };
    std::vector<int> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int size1 = first.size();
    int size2 = second.size();
    int size3 = third.size();
    int total = answers.size();

    int answer[3] = {0,0,0};

    for (int i = 0; i < total; ++i)
    {
        if (first[i % size1] == answers[i])
        {
            answer[0]++;
        }
        if (second[i % size2] == answers[i])
        {
            answer[1]++;
        }
        if (third[i % size3] == answers[i])
        {
            answer[2]++;
        }
    }
    std::vector<int> final;
    int max = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (max < answer[i])
        {
            max = answer[i];
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        if (max == answer[i])
        {
            final.push_back(i+1);
        }
    }

    return final;
}
