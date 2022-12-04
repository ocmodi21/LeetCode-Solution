#include <bits/stdc++.h>
using namespace std;

int minimumAverageDifference(vector<int> &nums)
{
    long long n = nums.size(), sum = 0;
    long long total = accumulate(begin(nums), end(nums), 0l);
    long long maxi = LLONG_MAX, ans = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        sum += nums[i];
        long long curr = abs(sum / (i + 1) - (total - sum) / (n - i - 1));
        if (curr < maxi)
            maxi = curr, ans = i;
    }

    return maxi > total / n ? n - 1 : ans;
}