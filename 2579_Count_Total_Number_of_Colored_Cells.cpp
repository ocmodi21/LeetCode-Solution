#include <bits/stdc++.h>
using namespace std;

// Approch-1
long long coloredCells(int n)
{
    long long ans = 1;
    for (int i = 2; i <= n; i++)
        ans += (i - 1) * 4;
    return ans;
}

// Approch-2
long long coloredCells(int n)
{
    return pow(n, 2) + pow(n - 1, 2);
}