#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stack>


class DFS
{
public:
    DFS();
    ~DFS();
    int DP_Solution(std::vector<int> numbers, int target);
    int DFS_Stack_solution(std::vector<int> numbers, int target);


};