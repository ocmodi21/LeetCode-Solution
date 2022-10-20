#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n*m)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == target)
                return 1;
        }
    }
    return 0;
}

// Approch-2 =>Time Complexity o(log(m*n))
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (n == 0 || m == 0)
        return false;

    int start = 0, end = m * n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int ind = matrix[mid / m][mid % m];
        if (target == ind)
            return true;
        else if (target < ind)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}

// Approch-3 =>Time Complexity o(log(m*n))
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int i = 0;
    int j = matrix[0].size() - 1;

    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        if (target < matrix[i][j])
            j--;
        else
            i++;
    }
    return false;
}