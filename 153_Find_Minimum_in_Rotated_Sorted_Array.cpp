#include <bits/stdc++.h>
using namespace std;

// Approch-1
int findMin(vector<int> &nums)
{
    return *min_element(nums.begin(), nums.end());
}

// Approch-2
int findMin(vector<int> &a)
{
    int l = 0, h = a.size() - 1, mid;
    while (l < h)
    {
        if (a[l] < a[h])
            return a[l];
        mid = (l + h) / 2;
        if (a[mid] < a[l])
            h = mid;
        else
            l = mid + 1;
    }
    return a[l];
}