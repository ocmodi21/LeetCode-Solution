#include <bits/stdc++.h>
using namespace std;

//Approch-1
bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
        v.push_back({nums[i], i});

    sort(v.begin(), v.end());

    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (v[m].first == target)
            return 1;
        else if (v[m].first < target)
            l = m + 1;
        else
            h = m - 1;
    }
    return 0;
}

//Approch-2
bool search(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int s = 0, n = nums.size();
    int e = n - 1;
    int m = s + (e - s) / 2;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (nums[m] == target)
            return true;
        else if (target > nums[m])
            s = m + 1;
        else
            e = m - 1;
    }
    return false;
}