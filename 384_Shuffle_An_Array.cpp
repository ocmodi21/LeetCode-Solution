#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> original;
    vector<int> duplicate;
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            original.push_back(nums[i]);
            duplicate.push_back(nums[i]);
        }
    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        int random = rand() % duplicate.size();
        swap(duplicate[0], duplicate[random]);
        return duplicate;
    }
};