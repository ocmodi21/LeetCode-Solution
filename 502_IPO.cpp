#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> mp(n);
    for (int i = 0; i < n; i++)
    {
        mp[i] = {capital[i], profits[i]};
    }

    sort(mp.begin(), mp.end());
    int i = 0;
    priority_queue<int> pq;
    while (k--)
    {

        while (i < n && mp[i].first <= w)
        {
            pq.push(mp[i].second);
            i++;
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }
    return w;
}