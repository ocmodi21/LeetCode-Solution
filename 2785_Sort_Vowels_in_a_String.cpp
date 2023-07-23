#include <bits/stdc++.h>
using namespace std;

bool isVowel(char s)
{
    if (s == 'A' || s == 'a' || s == 'E' || s == 'e' || s == 'I' ||
        s == 'i' || s == 'O' || s == 'o' || s == 'U' || s == 'u')
        return true;
    return false;
}

string sortVowels(string s)
{
    int n = s.size();
    string tempVowel;
    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
            tempVowel += s[i];
    }

    sort(tempVowel.begin(), tempVowel.end());
    string ans;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]) && ind < tempVowel.size())
        {
            ans += tempVowel[ind];
            ind++;
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}