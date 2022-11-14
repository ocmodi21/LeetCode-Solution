#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &a)
{
    int n = a.size();
    vector<int> left;
    stack<pair<int, int>> s1;
    int pseudoIndxeLeft = -1;

    for (int i = 0; i < n; i++)
    {
        if (s1.size() == 0)
            left.push_back(pseudoIndxeLeft);
        else if (s1.size() > 0 && s1.top().first < a[i])
            left.push_back(s1.top().second);
        else if (s1.size() > 0 && s1.top().first >= a[i])
        {
            while (s1.size() > 0 && s1.top().first >= a[i])
                s1.pop();
            if (s1.size() == 0)
                left.push_back(pseudoIndxeLeft);
            else
                left.push_back(s1.top().second);
        }
        s1.push({a[i], i});
    }

    vector<int> right;
    stack<pair<int, int>> s2;
    int pseudoIndxeRight = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
            right.push_back(pseudoIndxeRight);
        else if (s2.size() > 0 && s2.top().first < a[i])
            right.push_back(s2.top().second);
        else if (s2.size() > 0 && s2.top().first >= a[i])
        {
            while (s2.size() > 0 && s2.top().first >= a[i])
                s2.pop();
            if (s2.size() == 0)
                right.push_back(pseudoIndxeRight);
            else
                right.push_back(s2.top().second);
        }
        s2.push({a[i], i});
    }

    reverse(right.begin(), right.end());

    vector<int> width;
    for (int i = 0; i < n; i++)
    {
        int x = right[i] - left[i] - 1;
        width.push_back(x);
    }

    vector<int> area;
    for (int i = 0; i < n; i++)
    {
        int x = a[i] * width[i];
        area.push_back(x);
    }
    int m = *max_element(area.begin(), area.end());
    return m;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> v(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                v[j] = 0;
            else
                v[j]++;
        }
        int area = largestRectangleArea(v);
        ans = max(ans, area);
    }
    return ans;
}