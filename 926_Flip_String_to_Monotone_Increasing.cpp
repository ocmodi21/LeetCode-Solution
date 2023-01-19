#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int oneCount = 0, zeroCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            oneCount++;
        else
        {
            zeroCount++;
            zeroCount = min(zeroCount, oneCount);
        }
    }
    return zeroCount;
}