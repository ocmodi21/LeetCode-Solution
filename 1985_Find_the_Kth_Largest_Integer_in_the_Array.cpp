#include <bits/stdc++.h>
using namespace std;

static bool cmp(string &a, string &b)
{
    if (a.size() == b.size())
        return a > b;
    else
        return a.size() > b.size();
}
string kthLargestNumber(vector<string> &nums, int k)
{
    sort(nums.begin(), nums.end(), cmp);
    return nums[k - 1];
}