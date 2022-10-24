#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int m = (s + e) / 2;
        if (nums[m] == target)
            return m;
        if (nums[m] < target)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}