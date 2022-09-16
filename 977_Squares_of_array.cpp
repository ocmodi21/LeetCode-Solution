#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n)
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;

    vector<int> res(n);
    int pos = n - 1;

    while (start <= end)
    {
        if (abs(nums[start]) < abs(nums[end]))
        {
            res[pos--] = nums[end] * nums[end];
            end--;
        }
        else
        {
            res[pos--] = nums[start] * nums[start];
            start++;
        }
    }

    return res;
}

// Approch-2 =>Time Complexity o(nlogn)
vector<int> sortedSquares(vector<int> &nums)
{

    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i] * nums[i];
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    return v;
}