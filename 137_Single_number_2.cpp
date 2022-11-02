#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n) =>Space Complexity o(n)
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    for (auto x : m)
    {
        if (x.second == 1)
            return x.first;
    }
    return -1;
}

// Approch-2 =>Time Complexity o(nlogn) =>Space Complexity o(1)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    sort(nums.begin(), nums.end());

    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    for (int i = 1; i < n - 1; i++)
        if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
            return nums[i];
    return -1;
}

// Approch-3 =>Time Complexity o(n^2) =>Space Complexity o(1)
int singleNumber(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j] && i != j)
            {
                found = true;
            }
        }
        if (!found)
        {
            return nums[i];
        }
    }
    return -1;
}