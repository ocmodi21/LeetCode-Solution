#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<pair<int, int>> &vec, vector<vector<int>> &vis, vector<vector<int>> &grid, int baseRow, int baseCol)
{
    vis[row][col] = 1;
    vec.push_back({row - baseRow, col - baseCol});
    int n = grid.size();
    int m = grid[0].size();

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, vec, vis, grid, baseRow, baseCol);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, vec, vis, grid, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}