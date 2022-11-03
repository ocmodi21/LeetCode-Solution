#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    stack<int> s;
    vector<int> v;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() > prices[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            v.push_back(prices[i]);
        }
        else
        {
            v.push_back(prices[i] - s.top());
        }
        s.push(prices[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}