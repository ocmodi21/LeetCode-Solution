#include <bits/stdc++.h>
using namespace std;

// Approch-1
void findCombination(int ind, int n, int k, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ds.size() == k)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        ds.push_back(i + 1);
        findCombination(i + 1, n, k, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, n, k, ds, ans);
    return ans;
}

// Approch-2
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> temp(k, 0);
    int itr = 0;
    while (itr > -1)
    {
        temp[itr]++;
        if (temp[itr] > n)
            itr--;
        else if (itr == k - 1)
            res.push_back(temp);
        else
        {
            itr++;
            temp[itr] = temp[itr - 1];
        }
    }
    return res;
}