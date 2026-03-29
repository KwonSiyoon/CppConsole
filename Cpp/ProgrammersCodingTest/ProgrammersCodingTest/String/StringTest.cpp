#include "StringTest.h"

int StringTest::solution181871(string myString, string pat)
{
    int length = pat.length();
    int totalLength = myString.length();
    int answer = 0;
    for (int i = 0; i < totalLength - length + 1; ++i)
    {
        if (pat == myString.substr(i, length))
        {
            answer++;
        }
    }

    return answer;
}

string StringTest::solution181911(vector<string> my_strings, vector<vector<int>> parts)
{
    string answer = "";

    int length = my_strings.size();
    for (int i = 0; i < length; ++i)
    {
        int subLength = parts[i][1] - parts[i][0] + 1;
        answer += my_strings[i].substr(parts[i][0], subLength);
    }

    return answer;
}

vector<int> StringTest::solution181854(vector<int> arr, int n)
{
    //vector<int> answer;
    //int size = arr.size();
    //if (size % 2 == 0)
    //{
    //    // 짝수
    //    for (int i = 0; i < size; ++i)
    //    {
    //        if (i % 2 == 0)
    //        {
    //            answer.push_back(arr[i]);
    //        }
    //        else
    //        {
    //            answer.push_back(arr[i] + n);
    //        }
    //    }
    //}
    //else
    //{
    //    // 홀수
    //    for (int i = 0; i < size; ++i)
    //    {
    //        if (i % 2 != 0)
    //        {
    //            answer.push_back(arr[i]);
    //        }
    //        else
    //        {
    //            answer.push_back(arr[i] + n);
    //        }
    //    }
    //}
    //return answer;
    int size = arr.size();
    vector<int> answer(size);

    // 홀수면 짝수 인덱스에 더하고, 짝수면 홀수 인덱스에 더함
    int targetMod = (size % 2 == 0) ? 1 : 0;

    for (int i = 0; i < size; ++i)
    {
        answer[i] = (i % 2 == targetMod) ? arr[i] + n : arr[i];
    }

    return answer;

}

int StringTest::solution12943(int num)
{
    int answer = 0;
    long temp = num;
    while (answer < 500)
    {
        if (temp == 1)
        {
            return answer;
        }

        answer++;

        if (temp % 2 == 0)
        {
            // 짝수.
            temp = temp / 2;
        }
        else
        {
            // 홀수.
            temp = (temp * 3) + 1;
        }
    }
    return -1;
}

int solution(int num)
{
    if (num == 1) return 0;
    int answer = 0;
    long temp = num;
    while (answer < 500)
    {
        temp = (temp % 2 == 0) ? (temp / 2) : (temp * 3 + 1);
        answer++;
    }

    return (temp == 1) ? answer : -1;
}
