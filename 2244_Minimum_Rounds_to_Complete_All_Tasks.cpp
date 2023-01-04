#include <bits/stdc++.h>
using namespace std;

// Approch-1
int minimumRounds(vector<int> &tasks)
{
    int count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < tasks.size(); i++)
        mp[tasks[i]]++;

    for (auto x : mp)
    {
        if (x.second < 2)
            return -1;
        else
        {
            while (x.second > 1)
            {
                if (x.second % 3 == 1)
                    x.second -= 2;
                else
                    x.second -= 3;
                count++;
            }
        }
    }
    return count;
}

// Approch-2
int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> m;
    for (auto x : tasks)
    {
        m[x]++;
    }

    int count = 0;
    for (auto x : m)
    {
        int t = x.second;
        if (t == 1)
        {
            return -1;
        }
        count += t / 3;
        if (t % 3 != 0)
        {
            count++;
        }
    }
    return count;
}