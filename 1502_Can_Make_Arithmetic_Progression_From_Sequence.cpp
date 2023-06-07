#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int> &a)
{
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size() - 2; i++)
    {
        if (a[i + 1] - a[i] != a[i + 2] - a[i + 1])
            return false;
    }
    return true;
}