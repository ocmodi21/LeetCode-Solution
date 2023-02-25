#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxi = 0;
    int mini = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }
    return maxi;
}