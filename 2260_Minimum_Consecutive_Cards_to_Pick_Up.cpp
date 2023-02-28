#include <bits/stdc++.h>
using namespace std;

// Approch-1
int minimumCardPickup(vector<int> &cards)
{
    int ans = INT_MAX;
    unordered_map<int, int> mp;
    for (int i = 0; i < cards.size(); i++)
    {
        if (mp.find(cards[i]) != mp.end())
        {
            ans = min(ans, i - mp[cards[i]] + 1);
        }
        mp[cards[i]] = i;
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}

// Approch-2
int minimumCardPickup(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int result = INT_MAX;
    unordered_map<int, int> mp;
    int count = 0;

    while (j < nums.size())
    {
        mp[nums[j]]++;
        if (mp[nums[j]] > 1)
            count++;

        while (count >= 1)
        {
            result = min(result, j - i + 1);
            mp[nums[i]]--;
            if (mp[nums[i]] == 1)
                count--;
            i++;
        }
        j++;
    }
    return result == INT_MAX ? -1 : result;
}