#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0, ans = 0;
    while (j < fruits.size())
    {
        mp[fruits[j]]++;

        if (mp.size() <= 2)
        {
            ans = max(ans, j - i + 1);
        }

        else if (mp.size() > 2)
        {
            while (mp.size() > 2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}