#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int iniColor, int color, int delRow[], int delCol[], vector<vector<int>> &ans, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = color;

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color)
        {
            dfs(nRow, nCol, iniColor, color, delRow, delCol, ans, image);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, iniColor, color, delRow, delCol, ans, image);
    return ans;
}