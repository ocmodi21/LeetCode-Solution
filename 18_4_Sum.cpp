#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    long long n = nums.size();

    for (long long i = 0; i < n; i++)
    {
        long long target3 = target - nums[i];
        for (long long j = i + 1; j < n; j++)
        {
            long long target2 = target3 - nums[j];
            long long l = j + 1;
            long long h = n - 1;

            while (l < h)
            {
                long long sum = nums[l] + nums[h];
                if (sum == target2)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[h]);
                    ans.push_back(temp);

                    while (l < h && nums[l] == nums[l + 1])
                        l++;
                    while (l < h && nums[h] == nums[h - 1])
                        h--;
                }

                else if (sum < target2)
                    l++;
                else
                    h--;
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

// Approch-2
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> store;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int new_target = target - nums[i] - nums[j];
            int x = j + 1, y = n - 1;

            while (x < y)
            {
                int sum = nums[x] + nums[y];
                if (sum > new_target)
                    y--;
                else if (sum < new_target)
                    x++;
                else
                {
                    store.insert({nums[i], nums[j], nums[x], nums[y]});
                    x++;
                    y--;
                };
            }
        }
    }

    for (auto i : store)
    {
        ans.push_back(i);
    }

    return ans;
}