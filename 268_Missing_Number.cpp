#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int x = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    return x - sum;
}