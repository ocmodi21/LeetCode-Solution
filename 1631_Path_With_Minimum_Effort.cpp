#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &grid)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
            {
                int newEffort = max(abs(grid[nRow][nCol] - grid[row][col]), diff);

                if (newEffort < dist[nRow][nCol])
                {
                    dist[nRow][nCol] = newEffort;
                    pq.push({newEffort, {nRow, nCol}});
                }
            }
        }
    }
    return 0;
}
