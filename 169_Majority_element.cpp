#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(nlogn)
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[(nums.size()) / 2];
}

// Approch-2 =>Time Complexity o(n)
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> counter;
    for (int num : nums)
    {
        if (++counter[num] > nums.size() / 2)
        {
            return num;
        }
    }
    return 0;
}