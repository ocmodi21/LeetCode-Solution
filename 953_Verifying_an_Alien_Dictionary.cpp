#include <bits/stdc++.h>
using namespace std;

// Approch-1
unordered_map<char, int> mp;
bool cmp(string a, string b)
{
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] < mp[b[i]])
            return true;
        else if (mp[a[i]] > mp[b[i]])
            return false;
    }
    if (a.size() <= b.size())
        return true;
    return false;
}
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;

        vector<string> temp = words;
        sort(temp.begin(), temp.end(), cmp);
        return temp == words;
    }
};

// Approch-2
bool isAlienSorted(vector<string> &words, string order)
{
    unordered_map<char, int> map;
    for (int i = 0; i < order.length(); i++)
    {
        map[order[i]] = i;
    }
    for (int i = 1; i < words.size(); i++)
    {
        string first = words[i - 1];
        string second = words[i];
        int n = min(first.length(), second.length());
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (map[first[j]] < map[second[j]])
            {
                flag = true;
                break;
            }
            else if (map[first[j]] > map[second[j]])
            {
                return false;
            }
        }
        if (!flag && first.length() > second.length())
        {
            return false;
        }
    }
    return true;
}