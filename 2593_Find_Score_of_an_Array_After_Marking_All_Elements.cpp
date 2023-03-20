#include <bits/stdc++.h>
using namespace std;

long long findScore(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(nums[i], i));
    }
    while (!pq.empty())
    {
        int val = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        if (vis[index] == false)
        {
            ans += val;
            vis[index] = true;
            if (index > 0)
                vis[index - 1] = true;
            if (index < n - 1)
                vis[index + 1] = true;
        }
    }
    return ans;
}