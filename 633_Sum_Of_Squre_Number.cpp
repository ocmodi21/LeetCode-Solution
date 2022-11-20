#include <bits/stdc++.h>
using namespace std;

bool judgeSquareSum(int c)
{
    long long low = 0;
    long long high = (int)sqrt(c);

    while (low <= high)
    {
        if (low * low + high * high == c)
            return true;
        else if (low * low + high * high < c)
            low++;
        else
            high--;
    }
    return false;
}