#include <bits/stdc++.h>
using namespace std;

int rev(int n)
{
    int r, num = 0;
    while (n != 0)
    {
        r = n % 10;
        num = num * 10 + r;
        n /= 10;
    }
    return num;
}

int countDistinctIntegers(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums.push_back(rev(nums[i]));
    }
    set<int> s(nums.begin(), nums.end());
    return s.size();
}