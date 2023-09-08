#include <bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2)
{
    unordered_map<int, int> s1Even, s1Odd, s2Even, s2Odd;
    int n = s1.length();
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s1Even[s1[i]]++;
        else
            s1Odd[s1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s2Even[s2[i]]++;
        else
            s2Odd[s2[i]]++;
    }

    if (s1Even == s2Even && s1Odd == s2Odd)
        return true;
    return false;
}