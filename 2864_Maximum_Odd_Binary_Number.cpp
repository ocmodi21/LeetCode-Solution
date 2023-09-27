#include <bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s)
{
    sort(s.rbegin(), s.rend());
    int p = 0, n = s.size();
    while (p < n && s[p] == '1')
        p++;
    if (p == n)
        return s;
    swap(s[p - 1], s[n - 1]);
    return s;
}