#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    long long l = 0;
    long long h = x;
    int a;

    while (l <= h)
    {
        long long mid = (l + h) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            a = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return a;
}