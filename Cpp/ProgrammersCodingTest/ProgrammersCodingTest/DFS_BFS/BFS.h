#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

class BFS
{
public:
    BFS();
    ~BFS();
    int SearchSolution(std::vector<int> numbers, int target);
    long long BinarySearchSolution(int n, std::vector<int> times);
    
};