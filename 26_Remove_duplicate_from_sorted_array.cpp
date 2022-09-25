#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    int i = 0, j = 1;
    while (j < n)
    {
        if (nums[i] != nums[j])
        {
            swap(nums[i + 1], nums[j]);
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count + 1;
}