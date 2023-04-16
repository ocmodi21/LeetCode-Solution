#include <bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> maxCount(mat.size());
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
        }
        maxCount[i] = count;
    }

    int maxi = *max_element(maxCount.begin(), maxCount.end());
    for (int i = 0; i < maxCount.size(); i++)
    {
        if (maxCount[i] == maxi)
            return {i, maxCount[i]};
    }
    return {-1, -1};
}