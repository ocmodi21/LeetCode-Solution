#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    if (nums.size() == 1)
        return nums;

    vector<int> v;
    for (auto x : m)
    {
        if (x.second > (nums.size() / 3))
            v.push_back(x.first);
    }

    return v;
}