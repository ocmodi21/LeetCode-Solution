#include <bits/stdc++.h>
using namespace std;

int reversInt(int num)
{
    int rev_num = 0;
    int maxDigit = INT_MIN;
    while (num != 0)
    {
        rev_num = num % 10;
        maxDigit = max(maxDigit, rev_num);
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return maxDigit;
}

int maxSum(vector<int> &nums)
{
    int n = nums.size();
    int mxSum = -1;
    for (int i = 0; i < n; i++)
    {
        int num1 = reversInt(nums[i]);
        for (int j = 0; j < n; j++)
        {
            int num2 = reversInt(nums[j]);
            if (i != j)
            {
                if (num1 == num2)
                {
                    int sum = nums[i] + nums[j];
                    mxSum = max(mxSum, sum);
                }
            }
        }
    }
    return mxSum;
}