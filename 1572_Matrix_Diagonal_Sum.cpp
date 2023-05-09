#include <bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int primarySum = 0, secondarySum = 0;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        primarySum += mat[i][j];
        secondarySum += mat[i][n - 1 - j];
    }
    if (n % 2 == 1)
    {
        int mid = n / 2;
        secondarySum -= mat[mid][mid];
    }
    return primarySum + secondarySum;
}

