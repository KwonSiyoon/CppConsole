#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>



using namespace std;

string ltrim(const string&);
string rtrim(const string&);

using namespace std;


int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish)
{
    vector<int> schedule(t, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = start[i]; j < finish[i]; ++j)
        {
            schedule[j] = 1;
        }
    }

    int maxBreakTime = 0;
    int currentBreakTime = 0;

    for (int i = 0; i < t; ++i)
    {
        if (schedule[i] == 0)
        {
            ++currentBreakTime;
            maxBreakTime = max(maxBreakTime, currentBreakTime);
        }
        else
        {
            currentBreakTime = 0;
        }
    }

    return maxBreakTime;
}

int findBreakDuration2(int n, int k, int t, vector<int> start, vector<int> finish)
{
    int maxBreakTime = 0;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MAX));

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int moved = 0; moved <= k; ++moved)
        {
            if (dp[i][moved] == LLONG_MAX) continue;

            long long noMoveStart = max(dp[i][moved], (long long)start[i]);
            long long noMoveEnd = noMoveStart + (finish[i] - start[i]);
            dp[i + 1][moved] = min(dp[i + 1][moved], noMoveEnd);

            if (moved < k)
            {
                long long moveStart = dp[i][moved];
                long long moveEnd = moveStart + (finish[i] - start[i]);
                dp[i + 1][moved + 1] = min(dp[i + 1][moved + 1], moveEnd);

            }
        }
    }

    for (int moved = 0; moved <= k; ++moved)
    {
        if (dp[n][moved] != LLONG_MAX)
        {
            maxBreakTime = max(maxBreakTime, t - (int)dp[n][moved]);
        }
    }

    return maxBreakTime;
}

long getMinimumCost(vector<int> cost, int minWeight)
{

    int n = cost.size();
    const long INF = LLONG_MAX;
    vector<long> dp(minWeight + 100, INF);
    dp[0] = 0;


    for (int i = 0; i < n; ++i)
    {
        int weight = 1 << i;
        for (int w = weight; w < dp.size(); ++w)
        {
            if (dp[w - weight] != INF)
            {
                dp[w] = min(dp[w], dp[w - weight] + cost[i]);
            }
        }
    }
    long answer = INF;
    for (int w = minWeight; w < dp.size(); ++w)
    {
        answer = min(answer, dp[w]);
    }
    return answer;

    const long INF = numeric_limits<long>::max();
    int n = cost.size();
    vector<long> dp(minWeight + 100, INF);

    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int weight = 1 << i; 
        for (int w = weight; w < dp.size(); ++w)
        {
            if (dp[w - weight] != INF)
            {
                dp[w] = min(dp[w], dp[w - weight] + cost[i]);
            }
        }
    }

    long answer = INF;
    for (int w = minWeight; w < dp.size(); ++w)
    {
        answer = min(answer, dp[w]);
    }

    return answer == INF ? -1 : answer;


    const long INF = numeric_limits<long>::max();
    int n = cost.size();

    for (int i = n - 2; i >= 0; --i)
        cost[i] = min(cost[i], 2L * cost[i + 1]);

    vector<long> dp(minWeight + 100, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int weight = 1 << i; 
        for (int w = weight; w < dp.size(); ++w)
        {
            if (dp[w - weight] != INF)
            {
                dp[w] = min(dp[w], dp[w - weight] + cost[i]);
            }
        }
    }

    long answer = INF;
    for (int w = minWeight; w < dp.size(); ++w)
    {
        answer = min(answer, dp[w]);
    }

    return answer == INF ? -1 : answer;

}

vector<string> classifyEdges(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{

    const int INF = 1e9;
    vector<vector<pair<int, int>>> adj(g_nodes + 1);
    int m = g_from.size();

    for (int i = 0; i < m; ++i)
    {
        adj[g_from[i]].emplace_back(g_to[i], g_weight[i]);
        adj[g_to[i]].emplace_back(g_from[i], g_weight[i]);
    }

    // Dijkstra: 1 -> others
    auto dijkstra = [&](int start) {
        vector<int> dist(g_nodes + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u])
            {
                if (dist[v] > d + w)
                {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
        };

    vector<int> d1 = dijkstra(1);
    vector<int> dN = dijkstra(g_nodes);

    int shortest = d1[g_nodes];
    vector<string> answer(m, "NO");

    for (int i = 0; i < m; ++i)
    {
        int u = g_from[i], v = g_to[i], w = g_weight[i];
        if ((d1[u] + w + dN[v] == shortest) || (d1[v] + w + dN[u] == shortest))
        {
            answer[i] = "YES";
        }
    }

    return answer;
}


vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays)
{
    vector<pair<long long, int>> nums;

    for (int i = 0; i < bitArrays.size(); ++i)
    {
        long long value = 0;
        for (int bit : bitArrays[i])
        {
            value |= (1LL << bit);
        }
        nums.emplace_back(value, i);
    }

    sort(nums.rbegin(), nums.rend());

    vector<int> result;
    for (auto& p : nums) result.push_back(p.second);
    return result;

    vector<pair<long long, int>> values;

    for (int i = 0; i < bitArrays.size(); ++i)
    {
        long long val = 0;
        for (int b : bitArrays[i])
        {
            if (b >= 0 && b <= 60) val |= (1LL << b);
        }
        values.emplace_back(val, i);
    }

    sort(values.rbegin(), values.rend());

    vector<int> result;
    for (auto& [v, idx] : values) result.push_back(idx);
    return result;

}

long getMinimumCost(vector<int> cost, int minWeight)
{
    const long INF = 1e18;
    int n = cost.size();

    long result = INF;
    int maxState = 1 << n;

    for (int mask = 0; mask < maxState; ++mask)
    {
        long totalWeight = 0;
        long totalCost = 0;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                totalWeight += (1LL << i);
                totalCost += cost[i];
            }
        }

        if (totalWeight >= minWeight)
        {
            result = min(result, totalCost);
        }
    }

    return result;
}

int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish)
{
    using pii = pair<int, int>;
    vector<int> duration(n);
    for (int i = 0; i < n; i++) duration[i] = finish[i] - start[i];

    int possibleStart = 0;
    vector<pii> gains;
    for (int i = 0; i < n; i++)
    {
        int gain = start[i] - possibleStart;
        if (gain > 0) gains.emplace_back(gain, i);
        possibleStart += duration[i];
    }

    sort(gains.rbegin(), gains.rend());
    set<int> selected;
    for (int i = 0; i < min(k, (int)gains.size()); i++) selected.insert(gains[i].second);

    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (selected.count(i))
        {
            start[i] = currentTime;
            finish[i] = currentTime + duration[i];
        }
        else
        {
            start[i] = max(start[i], currentTime);
            finish[i] = start[i] + duration[i];
        }
        currentTime = finish[i];
    }

    return t - finish[n - 1];
}

long teamFormation(vector<int> score, int team_size, int k)
{
    using pii = pair<int, int>;
    long result = 0;
    int n = score.size();

    deque<pii> dq;
    for (int i = 0; i < n; i++) dq.emplace_back(score[i], i);

    multiset<pii> left, right;

    int leftPtr = 0, rightPtr = n - 1;

    for (int i = 0; i < k && leftPtr <= rightPtr; i++)
    {
        left.emplace(dq[leftPtr]);
        leftPtr++;
    }
    for (int i = 0; i < k && rightPtr >= leftPtr; i++)
    {
        right.emplace(dq[rightPtr]);
        rightPtr--;
    }

    for (int t = 0; t < team_size; t++)
    {
        pii pick = { -1, -1 };
        if (!left.empty()) pick = max(pick, left.rbegin());
        if (!right.empty()) pick = max(pick, right.rbegin());

        result += pick.first;

        if (left.find(pick) != left.end())
        {
            left.erase(left.find(pick));
            if (leftPtr <= rightPtr)
            {
                left.emplace(dq[leftPtr]);
                leftPtr++;
            }
        }
        else
        {
            right.erase(right.find(pick));
            if (rightPtr >= leftPtr)
            {
                right.emplace(dq[rightPtr]);
                rightPtr--;
            }
        }
    }

    return result;
}


bool canMake(int n, int k, int t, vector<int> start, vector<int> finish, int gap)
{
    int moveCount = 0;
    vector<int> s = start, f = finish;

    for (int i = 0; i < n - 1; ++i)
    {
        int needStart = f[i] + gap;

        if (s[i + 1] >= needStart) continue;

        int move = needStart - s[i + 1];
        if (f[i + 1] - s[i + 1] < move) return false;

        s[i + 1] += move;
        f[i + 1] += move;
        moveCount++;

        if (moveCount > k) return false;
    }

    return f[n - 1] <= t;
}

int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish)
{
    int low = 0, high = t, answer = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canMake(n, k, t, start, finish, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;
}


int main()
{

}