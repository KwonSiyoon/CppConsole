#include "DynamicProgrammingTest.h"

int DynamicProgrammingTest::IntTriangleSolution(std::vector<std::vector<int>> triangle)
{
    std::vector<int> sumSave;   // 이전 배열의 합.
    int height = triangle.size();
    sumSave.push_back(triangle[0][0]);
    for (int i = 1; i < height; ++i)
    {
        std::vector<int> sumTemplate(triangle[i].size());

        for (int j = 0; j<= i; ++j)
        {
            if (j == 0)
            {
                sumTemplate[j] = sumSave[0] + triangle[i][j];
            }
            else if (j == i)
            {
                sumTemplate[j] = sumSave[j - 1] + triangle[i][j];
            }
            else
            {
                sumTemplate[j] = std::max(sumSave[j - 1], sumSave[j]) + triangle[i][j];
            }
            /*int temp1 = sumSave[j] + triangle[i][j];
            int temp2 = sumSave[j] + triangle[i][j+1];
            sumTemplate[j] = temp1 >= temp2 ? temp1 : temp2;*/
        }
        /*sumSave.assign(sumTemplate.begin(), sumTemplate.end());
        sumTemplate.clear();*/
        sumSave = sumTemplate;
    }
    int answer = *std::max_element(sumSave.begin(), sumSave.end());

    return answer;
}
