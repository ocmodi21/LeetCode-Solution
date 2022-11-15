#include <bits/stdc++.h>
using namespace std;

int firstBadVersion(int n)
{
    int i = 0, j = n;
    while (i < j)
    {
        int m = i / 2 + j / 2;
        if (isBadVersion(m))
            j = m;
        else if (!isBadVersion(m))
            i = m + 1;
    }
    return i;
}