#include <bits/stdc++.h>
using namespace std;

int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.size() - 1;
    int mod = 1e9 + 7;
    int ans = 0;
    vector<int> pows(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++)
        pows[i] = (pows[i - 1] * 2) % mod;

    while (low <= high)
    {
        if (nums[low] + nums[high] > target)
            high--;
        else
            ans = (ans + pows[high - low++]) % mod;
    }
    return ans;
}