#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    int deleteCount = 0;
    unordered_map<int, bool> mp;
    vector<int> freq(26, 0);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        int frequency = freq[i];
        if (mp[frequency] == true)
        {
            while (mp[frequency] == true && frequency > 0)
            {
                frequency--;
                deleteCount++;
            }
            if (frequency > 0)
            {
                mp[frequency] = true;
            }
        }
        else
        {
            mp[frequency] = true;
        }
    }
    return deleteCount;
}