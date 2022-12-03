#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    priority_queue<pair<int, char>> pq;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;

    for (auto it : mp)
        pq.push({it.second, it.first});

    string ans = "";
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int freq = curr.first;
        while (freq > 0)
        {
            ans.push_back(curr.second);
            freq--;
        }
    }
    return ans;
}