#include <bits/stdc++.h>
using namespace std;

int countOdds(int low, int high)
{
    if ((high - low + 1) % 2 == 0)
        return (high - low + 1) / 2;
    else
    {
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low + 1) / 2;
        else if (low % 2 != 0 || high % 2 != 0)
            return (high - low + 1) / 2 + 1;
    }
    return -1;
}