#include <bits/stdc++.h>
using namespace std;

//Approch-1
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }

    int i = 0, j = 0;
    vector<int> ans;
    while (i < n / 2 && j < n / 2)
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[j]);
        i++;
        j++;
    }
    return ans;
}

//Approch-2
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int indexpos = 0, indexneg = 1;
    for (auto num : nums)
    {
        if (num > 0)
        {
            ans[indexpos] = num;
            indexpos += 2;
        }
        if (num < 0)
        {
            ans[indexneg] = num;
            indexneg += 2;
        }
    }
    return ans;
}