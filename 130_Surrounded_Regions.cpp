#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board)
{
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board[0].size(); i++)
    {
        if (!visited[0][i] && board[0][i] == 'O')
            dfs(0, i, visited, board);
        if (!visited[board.size() - 1][i] && board[board.size() - 1][i] == 'O')
            dfs(board.size() - 1, i, visited, board);
    }

    for (int i = 0; i < board.size(); i++)
    {
        if (!visited[i][0] && board[i][0] == 'O')
            dfs(i, 0, visited, board);
        if (!visited[i][board[0].size() - 1] && board[i][board[0].size() - 1] == 'O')
            dfs(i, board[0].size() - 1, visited, board);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (!visited[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &board)
{
    visited[row][col] = true;

    vector<int> delRow{0, 1, 0, -1};
    vector<int> delCol{1, 0, -1, 0};

    for (int i = 0; i < 4; i++)
    {
        int tempRow = delRow[i] + row;
        int tempCol = delCol[i] + col;

        if (tempRow >= 0 && tempRow < board.size() && tempCol >= 0 &&
            tempCol < board[0].size() && !visited[tempRow][tempCol] &&
            board[tempRow][tempCol] == 'O')
            dfs(tempRow, tempCol, visited, board);
    }
}