#include <bits/stdc++.h>
using namespace std;

// Binary Search
int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    int l = 0;
    int h = nums.size() - 1;
    while (l <= h)
    {
        if (nums[h] == val)
            h--;
        else if (nums[l] == val)
        {
            swap(nums[l], nums[h]);
            l++;
            h--;
        }
        else
            l++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            count++;
    }
    return count;
}

// Linear Search
int removeElement(vector<int> &nums, int val)
{
    int c = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[c++] = nums[i];
    }
    return c;
}