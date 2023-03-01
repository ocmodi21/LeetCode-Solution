#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    multiset<int> elements;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            elements.insert(matrix[i][j]);
    }
    auto smallest = elements.begin();
    k--;
    while (k--)
        smallest++;
    return *smallest;
}