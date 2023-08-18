#include <bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    int maxRank = 0;
    unordered_map<int, unordered_set<int>> adj;
    for (auto it : roads)
    {
        adj[it[0]].insert(it[1]);
        adj[it[1]].insert(it[0]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currRank = adj[i].size() + adj[j].size();
            if (adj[i].find(j) != adj[i].end())
                currRank--;
            maxRank = max(maxRank, currRank);
        }
    }
    return maxRank;
}