#include <bits/stdc++.h>
using namespace std;

int maximumNumberOfStringPairs(vector<string> &words)
{
    int n = words.size();
    vector<int> vis(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        reverse(words[i].begin(), words[i].end());
        for (int j = 0; j < n; j++)
        {
            if (vis[j] || j == i)
                continue;
            if (words[i] == words[j])
            {
                vis[i] = vis[j] = 1;
                ans++;
                break;
            }
        }
        reverse(words[i].begin(), words[i].end());
    }
    return ans;
}