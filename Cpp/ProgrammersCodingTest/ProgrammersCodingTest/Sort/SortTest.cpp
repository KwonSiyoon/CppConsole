#include "SortTest.h"
#include "iostream"


struct Compare
{
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
    {
        return a.first[0] < b.first[0];
    }
    bool operator()(const std::string& a, const std::string& b)
    {
        std::string ab;
        for (char c : a) ab.push_back(c);
        for (char c : b) ab.push_back(c);
        
        std::string ba;
        for (char c : b) ba.push_back(c);
        for (char c : a) ba.push_back(c);
        
        return ab < ba;
    }

    bool ToCompare(const std::string& a, const std::string& b)
    {
        return b + a < a + b;
    }
};




std::string SortTest::LargestNumberSolution(std::vector<int> numbers)
{
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> numberStrings;
    std::priority_queue<std::string, std::vector<std::string>, Compare> numberStrings2;
    std::vector<std::string> numberString3;
    std::sort(numberString3.begin(), numberString3.end(), Compare::ToCompare);
    for (auto& number : numbers)
    {
        numberStrings.emplace(std::to_string(number),number);
        numberStrings2.emplace(std::to_string(number));
    }

    std::string answer;
    while (!numberStrings2.empty())
    {
        answer.append(numberStrings2.top());
        numberStrings2.pop();
    }
    // 예외 처리: 모두 0일 경우
    if (!answer.empty() && answer[0] == '0')
    {
        return "0";
    }


    return answer;
}


