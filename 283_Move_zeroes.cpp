#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n)
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            nums[j++] = nums[i];
    }

    for (; j < n; j++)
        nums[j] = 0;
}

// Approch-2 =>Time Complexity o(n)
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;

    while (i < n)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else
            i++;
    }
}