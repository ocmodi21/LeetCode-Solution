#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int maxBar = 0;

    for (int i = 0; i < costs.size(); i++)
    {
        if (costs[i] <= coins)
        {
            coins -= costs[i];
            maxBar++;
        }
    }
    return maxBar;
}