#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    vector<int> v;
    int max = INT_MIN;

    for (int i = arr.size() - 1; i > 0; i--)
    {
        if (max < arr[i])
            max = arr[i];
        v.push_back(max);
    }
    reverse(v.begin(), v.end());
    v.push_back(-1);
    return v;
}