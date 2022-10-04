#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &a)
{
    vector<int> v;
    int n = a.size();
    int m = a[0].size();

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    int dir = 0;

    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
                v.push_back(a[top][i]);
            top++;
            dir = 1;
        }

        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
                v.push_back(a[i][right]);
            right--;
            dir = 2;
        }

        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                v.push_back(a[bottom][i]);
            bottom--;
            dir = 3;
        }

        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
                v.push_back(a[i][left]);
            left++;
            dir = 0;
        }
    }
    return v;
}