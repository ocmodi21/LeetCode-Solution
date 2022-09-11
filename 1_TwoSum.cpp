#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n^2)
vector<int> twoSum1(vector<int> &nums, int target)
{
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                v.push_back(i);
                v.push_back(j);
                break;
            }
        }
    }
    return v;
}

// Approch-2 =>Time Complexity o(n)
vector<int> twoSum2(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int y = target - x;

        if (m.find(y) != m.end())
            return {i, m[y]};
        m[nums[i]] = i;
    }
    return {-1, -1};
}

// Approch-3 =>Time Complexity o(nlogn)
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
        v.push_back({nums[i], i});

    sort(v.begin(), v.end());

    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        int sum = v[l].first + v[h].first;

        if (sum == target)
            return {v[l].second, v[h].second};
        else if (sum < target)
            l++;
        else
            h--;
    }
    return {-1, -1};
}