#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[0][0] = 1;
    pq.push({grid[0][0], {0, 0}});

    int delRow[] = {0, 1};
    int delCol[] = {1, 0};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int totalSum = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return totalSum;

        for (int i = 0; i < 2; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol])
            {
                pq.push({totalSum + grid[nRow][nCol], {nRow, nCol}});
                vis[nRow][nCol] = 1;
            }
        }
    }
    return -1;
}