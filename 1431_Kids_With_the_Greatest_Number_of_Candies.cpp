#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> ans(candies.size(), false);
    int maxi = *max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++)
    {
        int temp = candies[i] + extraCandies;
        if (temp >= maxi)
            ans[i] = true;
    }
    return ans;
}