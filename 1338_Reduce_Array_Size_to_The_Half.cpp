#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int minSetSize(vector<int> &arr)
{
    int size = arr.size();
    unordered_map<int, int> mp;
    vector<pair<int, int>> fq;

    for (int i = 0; i < size; i++)
        mp[arr[i]]++;
    for (auto a : mp)
        fq.push_back(a);
    sort(fq.begin(), fq.end(), cmp);

    int ans = 0;
    auto i = fq.begin();
    while (size > arr.size() / 2)
    {
        size -= i->second;
        ans++;
        i++;
    }
    return ans;
}