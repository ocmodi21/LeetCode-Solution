#include <bits/stdc++.h>
using namespace std;

// Approch-1
long long int sum(long long int x)
{
    return x * (x + 1) / 2;
}

int arrangeCoins(int n)
{
    if (n == 1)
        return 1;
    long long int i = 1, j = n;
    while (i < j)
    {
        long long int m = (i + j) / 2;
        if (sum(m) == n)
            return m;
        else if (sum(m) < n)
            i = m + 1;
        else
            j = m;
    }
    return i - 1;
}

// Approch-2
int arrangeCoins(int n)
{
    int i = 1;
    while (n >= i)
    {
        n -= i;
        i++;
    }

    return --i;
}
