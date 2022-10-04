#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
        m[nums[i]]++;

    for (auto x : m)
    {
        if (x.second > 1)
            return 1;
    }

    return 0;
}