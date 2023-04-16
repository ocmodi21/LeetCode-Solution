#include <bits/stdc++.h>
using namespace std;

int maxDivScore(vector<int> &nums, vector<int> &divisors)
{
    int res = INT_MIN;
    int maxi = INT_MIN;
    for (int i = 0; i < divisors.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] % divisors[i] == 0)
                count++;
        }
        if (maxi < count)
        {
            maxi = count;
            res = divisors[i];
        }
        if (maxi == count)
        {
            if (res > divisors[i])
                res = divisors[i];
        }
    }
    return res;
}