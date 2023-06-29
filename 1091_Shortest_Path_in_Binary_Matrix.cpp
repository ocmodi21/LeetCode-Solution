#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    grid[0][0] = -1;

    int delRow[] = {-1, 0, 1, 0, 1, -1, -1, 1};
    int delCol[] = {0, 1, 0, -1, 1, 1, -1, -1};

    while (!q.empty())
    {
        auto val = q.front();
        int row = val.first.first;
        int col = val.first.second;
        int path = val.second;
        q.pop();

        if (row == n - 1 && col == n - 1)
            return path;

        for (int i = 0; i < 8; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0)
            {
                grid[nRow][nCol] = -1;
                q.push({{nRow, nCol}, path + 1});
            }
        }
    }
    return -1;
}