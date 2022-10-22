#include <bits/stdc++.h>
using namespace std;

int rev(int n)
{
    int r, num = 0;
    while (n != 0)
    {
        r = n % 10;
        num = num * 10 + r;
        n /= 10;
    }
    return num;
}

bool sumOfNumberAndReverse(int num)
{
    if (num == 0)
        return 1;
    for (int i = 1; i < num; i++)
    {
        if (i + rev(i) == num)
            return 1;
    }
    return 0;
}