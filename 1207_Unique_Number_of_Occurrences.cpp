#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
        m[arr[i]]++;

    vector<int> v;
    for (auto x : m)
        v.push_back(x.second);

    set<int> st(v.begin(), v.end());

    if (st.size() == v.size())
        return 1;
    else
        return 0;
}