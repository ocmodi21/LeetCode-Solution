#include <bits/stdc++.h>
using namespace std;

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < nums1.size(); i++)
        v.push_back({nums2[i], nums1[i]});
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    long long int sum = 0, ans = 0;
    for (int i = nums1.size() - 1; i >= 0; i--)
    {
        sum += v[i].second * 1LL;
        pq.push(v[i].second);
        while (pq.size() > k)
        {
            sum -= pq.top() * 1LL;
            pq.pop();
        }
        if (pq.size() == k)
            ans = max(ans, sum * 1LL * v[i].first);
    }
    return ans;
}