#include <bits/stdc++.h>
using namespace std;

int addMinimum(string word)
{
    int ans = 0;
    int i = 0;
    while (i < word.size())
    {
        int count = 0;
        if (word[i] == 'a')
        {
            count++;
            i++;
        }
        if (word[i] == 'b' && i < word.size())
        {
            count++;
            i++;
        }
        if (word[i] == 'c' && i < word.size())
        {
            count++;
            i++;
        }
        ans += 3 - count;
    }
    return ans;
}