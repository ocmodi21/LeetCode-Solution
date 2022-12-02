#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    for (int i = 0; i <= (int)(haystack.length() - needle.length()); i++)
    {
        if (haystack.substr(i, needle.length()) == needle)
            return i;
    }
    return -1;
}