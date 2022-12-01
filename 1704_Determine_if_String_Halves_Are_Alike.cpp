#include <bits/stdc++.h>
using namespace std;

bool halvesAreAlike(string s)
{
    int left_count = 0;
    int right_count = 0;

    for (int i = 0; i < (s.length()) / 2; i++)
    {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' ||
            s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' ||
            s[i] == 'U' || s[i] == 'u')
            left_count++;
    }

    for (int i = (s.length()) / 2; i < s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' ||
            s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' ||
            s[i] == 'U' || s[i] == 'u')
            right_count++;
    }

    if (left_count == right_count)
        return true;
    else
        return false;
}