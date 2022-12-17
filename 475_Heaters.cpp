#include <bits/stdc++.h>
using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> ans(houses.size(), INT_MAX);
    int i = 0, j = 0;
    while (i < houses.size() && j < heaters.size())
    {
        if (houses[i] <= heaters[j])
        {
            ans[i] = abs(houses[i] - heaters[j]);
            i++;
        }
        else
            j++;
    }
    i = houses.size() - 1, j = heaters.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (houses[i] >= heaters[j])
        {
            ans[i] = min(abs(houses[i] - heaters[j]), ans[i]);
            i--;
        }
        else
            j--;
    }
    return *max_element(ans.begin(), ans.end());
}