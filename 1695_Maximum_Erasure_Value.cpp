#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int> &a)
{
    int score = 0, maxScore = 0;
    int j = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
        score += a[i];
        if (i - j + 1 == mp.size())
            maxScore = max(maxScore, score);
        else if (i - j + 1 > mp.size())
        {
            while (i - j + 1 > mp.size())
            {
                score -= a[j];
                mp[a[j]]--;
                if (mp[a[j]] == 0)
                    mp.erase(a[j]);
                j++;
            }
        }
    }
    return maxScore;
}