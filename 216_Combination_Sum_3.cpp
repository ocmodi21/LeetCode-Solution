#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int sum, int k, int n, vector<int> &ds,vector<vector<int>> &ans)
{
    if (sum == n && k == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (ind == 10)
        return;
    if (sum > n)
        return;

    ds.push_back(ind);
    sum += ind;
    findCombination(ind + 1, sum, k - 1, n, ds, ans);
    sum -= ind;
    ds.pop_back();
    findCombination(ind + 1, sum, k, n, ds, ans);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(1, 0, k, n, ds, ans);
    return ans;
}