#include <bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int> &skill)
{
    sort(skill.begin(), skill.end());

    vector<pair<int, int>> v;
    int ans = skill[0] + skill[skill.size() - 1];

    int i = 0, j = skill.size() - 1;
    while (i < j)
    {
        if (skill[i] + skill[j] == ans)
            v.push_back(make_pair(skill[i], skill[j]));
        else
            return -1;
        i++;
        j--;
    }
    long long sum = 0;
    for (auto i : v)
        sum = (i.first * i.second) + sum;
    return sum;
}