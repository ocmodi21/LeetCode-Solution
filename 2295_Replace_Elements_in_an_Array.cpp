#include <bits/stdc++.h>
using namespace std;

vector<int> arrayChange(vector<int> &a, vector<vector<int>> &operations)
{
    unordered_map<int, int> positions;
    vector<int> changedArray(a.size());
    for (int i = 0; i < a.size(); i++)
        positions[a[i]] = i;

    for (int i = 0; i < operations.size(); i++)
    {
        int preIndex = positions[operations[i][0]];
        positions.erase(operations[i][0]);
        positions[operations[i][1]] = preIndex;
    }

    for (auto i : positions)
        changedArray[i.second] = i.first;
    return changedArray;
}