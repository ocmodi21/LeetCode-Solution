#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int product = 1;
    int i = 0;
    int ans = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        product *= nums[j];
        while (i <= j && product >= k)
        {
            product /= nums[i];
            i++;
        }
        ans += (j - i + 1);
    }
    return ans;
}