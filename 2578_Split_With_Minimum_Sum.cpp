#include <bits/stdc++.h>
using namespace std;

int splitNum(int num)
{
    string s = to_string(num);
    sort(s.begin(), s.end());
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2)
            a = 10 * a + s[i] - '0';
        else
            b = 10 * b + s[i] - '0';
    }
    return a + b;
}