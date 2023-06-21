#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> &a, vector<int> &cost)
{
    vector<pair<int, int>> costMap;
    vector<long long> preCosts;
    long long minimumCost = 0, currentCost = 0;
    long long sum = 0;

    for (int i = 0; i < a.size(); i++)
        costMap.push_back({a[i], cost[i]});
    sort(costMap.begin(), costMap.end());

    for (int i = 0; i < costMap.size(); i++)
    {
        sum += costMap[i].second;
        preCosts.push_back(sum);
    }

    for (int i = 1; i < costMap.size(); i++)
        currentCost += (costMap[i].first - costMap[0].first) *
                       (long long)costMap[i].second;
    minimumCost = currentCost;

    for (int i = 1; i < costMap.size(); i++)
    {
        int diff = costMap[i].first - costMap[i - 1].first;
        currentCost += (long long)diff * (preCosts[i - 1]);
        currentCost -= (long long)diff *
                       (preCosts[preCosts.size() - 1] - preCosts[i - 1]);
        minimumCost = min(minimumCost, currentCost);
    }
    return minimumCost;
}