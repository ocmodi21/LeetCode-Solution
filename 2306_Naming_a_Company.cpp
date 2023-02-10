#include <bits/stdc++.h>
using namespace std;

// Approch-1
long long distinctNames(vector<string> &ideas)
{
    unordered_map<string, int> mp;
    for (auto x : ideas)
        mp[x]++;

    unordered_map<string, int> name;
    for (int i = 0; i < ideas.size(); i++)
    {
        for (int j = 0; j < ideas.size(); j++)
        {
            if (ideas[i] != ideas[j])
            {
                string ideaA = ideas[i];
                string ideaB = ideas[j];
                swap(ideaA[0], ideaB[0]);
                if (mp.find(ideaA) != mp.end() || mp.find(ideaB) != mp.end())
                {
                    continue;
                }
                else
                {
                    name[ideaA + ideaB]++;
                }
            }
        }
    }
    long long distinctName = 0;
    for (auto x : name)
        distinctName += x.second;
    return distinctName;
}

//Approch-2
