#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> weights, int days, int mid)
{
    int sum = 0;
    int time = 1;
    for (int it : weights)
    {
        if (sum + it <= mid)
        {
            sum += it;
        }
        else
        {
            time++;
            sum = it;
        }
    }
    if (time > days)
        return false;
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = 0, high = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(weights, days, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}