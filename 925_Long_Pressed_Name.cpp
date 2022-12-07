#include <bits/stdc++.h>
using namespace std;

bool isLongPressedName(string name, string typed)
{

    int n = name.size(), m = typed.size();
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (name[i] == typed[j])
        {
            ++i;
            ++j;
        }
        else if (j > 0 && typed[j] == typed[j - 1])
        {
            ++j;
        }
        else
        {
            return false;
        }
    }

    while (j < m && typed[j] == typed[j - 1])
        ++j;

    if (i == n && j == m)
        return true;
    return false;
}