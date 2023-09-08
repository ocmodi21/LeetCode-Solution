#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;

    ans.push_back({1});
    for (int i = 1; i < numRows; ++i)
    {
        vector<int> prev_row = ans.back();
        vector<int> new_row = {1};

        for (int j = 1; j < prev_row.size(); ++j)
        {
            new_row.push_back(prev_row[j - 1] + prev_row[j]);
        }
        new_row.push_back(1);
        ans.push_back(new_row);
    }
    return ans;
}