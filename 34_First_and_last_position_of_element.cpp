#include <bits/stdc++.h>
using namespace std;

//Approch-1
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int h = n - 1;
    vector<int> v;

    while (l <= h)
    {
        int mid = (l + (h - l)) / 2;

        if ((mid == 0 || target > nums[mid - 1]) && nums[mid] == target)
            v.push_back(mid);
        else if (nums[mid] < target)
            l = mid + 1;
        else if (nums[mid] > target)
            h = mid - 1;
        else
            v.push_back(-1);
    }

    l = 0;
    h = n - 1;

    while (l <= h)
    {
        int mid = (l + (h - l)) / 2;

        if ((mid == n - 1 || target > nums[mid + 1]) && nums[mid] == target)
            v.push_back(mid);
        else if (nums[mid] < target)
            l = mid + 1;
        else if (nums[mid] > target)
            h = mid - 1;
        else
            v.push_back(-1);
    }
    return v;
}

//Approch-2
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int first = -1, last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
                last = i;
            }
            else
                last = i;
        }
    }
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}