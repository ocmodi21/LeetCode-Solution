#include <bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    long long ans = 0;
    while (k-- && pq.size() > 0)
    {
        long long res = pq.top();
        pq.pop();
        ans += res;
        if (res % 3 == 0)
            res /= 3;
        else
            res = (res / 3) + 1;
        pq.push(res);
    }
    return ans;
}