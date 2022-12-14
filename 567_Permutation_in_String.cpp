#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string ptr, string txt)
{
    int len = ptr.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[ptr[i]]++;
    int count = mp.size();

    int i = 0, j = 0;
    while (j < txt.size())
    {

        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < len)
            j++;

        else if (j - i + 1 == len)
        {
            if (count == 0)
            {
                return true;
            }

            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return false;
}