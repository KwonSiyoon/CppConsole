#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr);

int main()
{
    vector<int> arr = { 1,1,3,3,0,1,1 };
    vector<int> ans = solution(arr);
    for (int num : ans)
    {
        cout << num << "\n";
    }
}

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> que;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!que.empty() && que.back() == arr[i])
        {
            continue;
        }
        que.push(arr[i]);
    }
    for (int i = 0; i < que.size(); ++i)
    {
        answer.push_back(que.front());
        que.pop();
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}