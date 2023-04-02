#include <bits/stdc++.h>
using namespace std;

int minNumber(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    int mini = INT_MAX;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            mini = min(mini, nums1[i]);
            return mini;
        }
        if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }

    int firstMin = nums1[0];
    int secondMin = nums2[0];
    if (firstMin > secondMin)
        mini = (secondMin * 10) + firstMin;
    else
        mini = (firstMin * 10) + secondMin;
    return mini;
}