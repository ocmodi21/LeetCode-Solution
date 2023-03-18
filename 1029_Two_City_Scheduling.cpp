#include <bits/stdc++.h>
using namespace std;

// Approch-1
int twoCitySchedCost(vector<vector<int>> &costs)
{
    vector<int> refund;
    int N = costs.size() / 2;
    int minCost = 0;
    for (vector<int> cost : costs)
    {
        minCost += cost[0];
        refund.push_back(cost[1] - cost[0]);
    }
    sort(refund.begin(), refund.end());
    for (int i = 0; i < N; i++)
    {
        minCost += refund[i];
    }
    return minCost;
}

// Approch-2
int twoCitySchedCost(vector<vector<int>> &costs)
{
    vector<pair<int, int>> difference;
    int sum = 0;
    for (int i = 0; i < costs.size(); i++)
        difference.push_back({costs[i][0] - costs[i][1], i});
    sort(difference.begin(), difference.end());
    for (int i = 0; i < difference.size(); i++)
    {
        if (i < difference.size() / 2)
            sum += costs[difference[i].second][0];
        else
            sum += costs[difference[i].second][1];
    }
    return sum;
}