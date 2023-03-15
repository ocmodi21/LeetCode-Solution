#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;

public:
    Solution(vector<int> &nums)
    {
        ans = nums;
    }
    int pick(int target)
    {
        int random = 0, index = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == target)
            {
                random++;
                if (rand() % random == 0)
                    index = i;
            }
        }
        return index;
    }
};