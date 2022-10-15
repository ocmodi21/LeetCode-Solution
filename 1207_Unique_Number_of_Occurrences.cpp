#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
        m[arr[i]]++;
    int count = 0;
    for (auto x : m)
    {
        if (x.second == 1)
            count++;
    }

    if (count == 1)
        return 1;
    else
        return 0;
}