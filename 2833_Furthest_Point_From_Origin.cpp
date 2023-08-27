#include <bits/stdc++.h>
using namespace std;

int furthestDistanceFromOrigin(string moves)
{
    int left = 0;
    int extra = 0;
    for (auto ele : moves)
    {
        if (ele == '_')
            extra++;
        else if (ele == 'L')
            left--;
        else
            left++;
    }

    return abs(left) + extra;
}