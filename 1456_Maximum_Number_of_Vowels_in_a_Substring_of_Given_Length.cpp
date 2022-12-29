#include <bits/stdc++.h>
using namespace std;

bool isVowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    return false;
}
int maxVowels(string s, int k)
{
    int i = 0, j = 0, count = 0, ans = 0;
    while (j < s.size())
    {
        if (isVowel(s[j]))
            count++;
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans = max(ans, count);
            if (isVowel(s[i]))
                count--;
            i++;
            j++;
        }
    }
    return ans;
}