#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                q.push({nRow, nCol});
                vis[nRow][nCol] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}