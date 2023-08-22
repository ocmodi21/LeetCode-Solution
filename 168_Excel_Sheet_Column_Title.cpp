#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int c)
{
    string s = "";
    while (c > 0)
    {
        c = c - 1;
        char ch = 'A' + c % 26;
        s += ch;
        c /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
}