#include <bits/stdc++.h>
using namespace std;

int similarPairs(vector<string> &words)
{
    vector<set<char>> ans;
    for (int i = 0; i < words.size(); i++)
    {
        set<char> temp(words[i].begin(), words[i].end());
        ans.push_back(temp);
    }
    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            if (i != j && ans[i] == ans[j])
                count++;
        }
    }
    return count / 2;
}
