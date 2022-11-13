#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num)
{
    long long l = 0;
    long long h = num;

    while (l <= h)
    {
        long long mid = (l + h) / 2;
        if (mid * mid == num)
            return true;
        else if (mid * mid > num)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}