#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>> &grid)
{
    unordered_map<string, int> mp;
    int totalPairs = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        string currRow;
        for (int j = 0; j < grid[0].size(); j++)
        {
            currRow += to_string(grid[i][j]);
            currRow += ",";
        }
        mp[currRow]++;
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        string currCol;
        for (int j = 0; j < grid.size(); j++)
        {
            currCol += to_string(grid[j][i]);
            currCol += ",";
        }
        if (mp[currCol])
        {
            totalPairs += mp[currCol];
        }
    }
    return totalPairs;
}