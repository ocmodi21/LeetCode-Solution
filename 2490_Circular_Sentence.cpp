#include <bits/stdc++.h>
using namespace std;

bool isCircularSentence(string s)
{
    if (s[0] != s[s.length() - 1])
        return false;
    int i = 1;
    int s_count = 0;
    int e_count = 0;
    while (i < s.length() - 1)
    {
        if (s[i] == ' ')
        {
            if (s[i - 1] != s[i + 1])
                return false;
        }
        i++;
    }
    return true;
}