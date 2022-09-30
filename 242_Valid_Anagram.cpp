#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s.length() != t.length())
        return 0;
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
                return 0;
        }
    }
    return 1;
}