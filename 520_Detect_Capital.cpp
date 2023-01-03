#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;
    int n = word.size();
    for (int i = 0; i <= n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            count++;
    }
    if (count == 0 || count == n || (word[0] >= 'A' && word[0] <= 'Z' && count == 1))
        return true;
    return false;
}