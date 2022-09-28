#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int f = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        if (mp[i] == 0)
        {
            f = i;
            break;
        }
    }
    return f;
}