#include <bits/stdc++.h>
using namespace std;

string smallestString(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 'a')
        {
            s[i] = s[i] - 1;
            count++;
        }
        else if (count)
        {
            break;
        }
    }
    if (count == 0)
    {
        s[s.size() - 1] = 'z';
    }
    return s;
}