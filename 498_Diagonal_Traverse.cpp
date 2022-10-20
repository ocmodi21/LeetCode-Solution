#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    vector<int> ans;
    map<int, vector<int>> m;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            m[i + j].push_back(mat[i][j]);
        }
    }

    for (auto i : m)
    {
        if (i.first % 2 == 0)
        {
            for (int j = i.second.size() - 1; j >= 0; j--)
                ans.push_back(i.second[j]);
        }
        else
        {
            for (int j = 0; j < i.second.size(); j++)
                ans.push_back(i.second[j]);
        }
    }
    return ans;
}