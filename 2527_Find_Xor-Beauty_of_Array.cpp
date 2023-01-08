#include <bits/stdc++.h>
using namespace std;

int xorBeauty(vector<int> &nums)
{
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}