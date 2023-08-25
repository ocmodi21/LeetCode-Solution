#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    vector<int> f(26, 0);
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        f[s[i] - 'a']++;
        if (f[s[i] - 'a'] > (n + 1) / 2)
            return "";
    }
    priority_queue<pair<int, char>> p;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] != 0)
        {
            p.push({f[i], (char)i + 'a'});
        }
    }

    string ans = "";
    while (p.size() >= 2)
    {
        auto it1 = p.top();
        p.pop();
        auto it2 = p.top();
        p.pop();

        ans += it1.second;
        ans += it2.second;

        if (it1.first > 1)
        {
            p.push({it1.first - 1, it1.second});
        }
        if (it2.first > 1)
        {
            p.push({it2.first - 1, it2.second});
        }
    }
    if (p.size() == 1)
    {
        ans += p.top().second;
    }
    return ans;
}