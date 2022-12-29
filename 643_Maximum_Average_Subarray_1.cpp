#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int n = nums.size();
    double ans = INT_MIN, sum = 0;
    while (j < n)
    {
        sum += nums[j];
        double avg = sum / k;
        if (j - i + 1 == k)
        {
            ans = max(ans, avg);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return ans;
}