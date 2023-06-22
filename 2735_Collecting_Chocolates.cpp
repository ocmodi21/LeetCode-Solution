#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> &costs, int x)
{
    vector<int> minCosts(costs.size(), INT_MAX);
    long long minSum = LONG_MAX;

    for (int i = 0; i < costs.size(); i++)
    {
        long long sum = (long long)x * i;
        for (int j = 0; j < costs.size(); j++)
        {
            minCosts[j] = min(minCosts[j], costs[(i - j + costs.size()) % costs.size()]);
            sum += minCosts[j];
        }
        minSum = min(minSum, sum);
    }
    return minSum;
}