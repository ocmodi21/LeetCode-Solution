#include <bits/stdc++.h>
using namespace std;

int subarrayGCD(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = i; j < n; j++)
        {
            x = __gcd(x, nums[j]);
            if (x == k)
                count++;
        }
    }
    return count;
}