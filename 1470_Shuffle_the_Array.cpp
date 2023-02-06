#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<int> shuffle(vector<int> &nums, int n)
{
    int k = 0, i = 0, j = n;
    vector<int> ans(2 * n);
    while (k < 2 * n)
    {
        ans[k++] = nums[i++];
        ans[k++] = nums[j++];
    }
    return ans;
}

// Approch-2
vector<int> shuffle(vector<int> &a, int n)
{
    vector<int> shuffledArray;
    for (int i = 0; i < a.size() / 2; i++)
    {
        shuffledArray.push_back(a[i]);
        shuffledArray.push_back(a[a.size() / 2 + i]);
    }
    return shuffledArray;
}