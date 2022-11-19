#include <bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;
        int last = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 0)
            {
                last = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans.push_back(last);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < ans.size(); i++)
    {
        v.push_back({ans[i], i});
    }
    sort(v.begin(), v.end());
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(v[i].second);
    }
    return res;
}