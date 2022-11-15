#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] < nums[mid + 1])
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}