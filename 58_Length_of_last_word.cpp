#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int len = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            len++;
        else if (len > 0)
            return len;
    }

    return len;
}