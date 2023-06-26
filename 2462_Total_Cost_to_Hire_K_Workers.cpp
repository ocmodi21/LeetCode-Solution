#include <bits/stdc++.h>
using namespace std;

long long totalCost(vector<int> &costs, int k, int c)
{
    int n = costs.size();
    priority_queue<int, vector<int>, greater<int>> left, right;
    int low = 0, high = n - 1;
    long long ans = 0;

    while (k--)
    {
        while (left.size() < c && low <= high)
        {
            left.push(costs[low]);
            low++;
        }
        while (right.size() < c && low <= high)
        {
            right.push(costs[high]);
            high--;
        }

        int min1 = INT_MAX, min2 = INT_MAX;
        if (left.size())
            min1 = left.top();
        if (right.size())
            min2 = right.top();
        if (min1 <= min2)
        {
            ans += min1;
            left.pop();
        }
        else
        {
            ans += min2;
            right.pop();
        }
    }
    return ans;
}