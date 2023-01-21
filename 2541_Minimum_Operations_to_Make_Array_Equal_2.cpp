#include <bits/stdc++.h>
using namespace std;

long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
{
    long long ans = 0;
    long long positive = 0, negative = 0;
    if (k == 0)
    {
        return nums1 == nums2 ? 0 : -1;
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        int diff = nums1[i] - nums2[i];
        if (diff % k)
            return -1;
        if (diff > 0)
            positive += diff;
        else
            negative += diff;
    }

    if ((positive + negative) != 0)
        return -1;
    ans = positive / k;
    return ans;
}