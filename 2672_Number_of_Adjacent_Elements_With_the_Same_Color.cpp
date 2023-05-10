#include <bits/stdc++.h>
using namespace std;

vector<int> colorTheArray(int n, vector<vector<int>> &queries)
{
    vector<int> ans;
    vector<int> elements(n, 0);
    int adjacent = 0;
    for (int i = 0; i < queries.size(); i++)
    {
        if (elements[queries[i][0]] != 0 && queries[i][0] != 0 &&
            elements[queries[i][0]] == elements[queries[i][0] - 1])
            --adjacent;
        if (elements[queries[i][0]] != 0 && queries[i][0] != n - 1 &&
            elements[queries[i][0]] == elements[queries[i][0] + 1])
            --adjacent;

        elements[queries[i][0]] = queries[i][1];

        if (elements[queries[i][0]] != 0 && queries[i][0] != 0 &&
            elements[queries[i][0]] == elements[queries[i][0] - 1])
            ++adjacent;
        if (elements[queries[i][0]] != 0 && queries[i][0] != n - 1 &&
            elements[queries[i][0]] == elements[queries[i][0] + 1])
            ++adjacent;

        ans.push_back(adjacent);
    }
    return ans;
}