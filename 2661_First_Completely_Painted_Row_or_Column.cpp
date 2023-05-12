#include <bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int> &a, vector<vector<int>> &mat)
{
    vector<int> rowStatus(mat.size(), 0), colStatus(mat[0].size(), 0);
    unordered_map<int, pair<int, int>> matMap;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            matMap[mat[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        auto current = matMap[a[i]];

        rowStatus[current.first]++;
        colStatus[current.second]++;
        if (rowStatus[current.first] == mat[0].size() ||
            colStatus[current.second] == mat.size())
            return i;
    }
    return 0;
}